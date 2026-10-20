"""Verify targeted FM instruction evidence and classify native export warnings."""
import collections
import hashlib
import json
import re
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
OUT = ROOT / 'analysis/final-mix/native-pseudocode'
binary = (ROOT / 'tools/kh2-reference/SLPM_666.75').read_bytes()
expected_hash = 'd869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
assert hashlib.sha256(binary).hexdigest() == expected_hash

def words(address, count):
    offset = address - 0x100000 + 0x1000
    return list(struct.unpack_from('<' + 'I' * count, binary, offset))

for address in (0x1391e8, 0x1391f0, 0x1391f8):
    assert words(address, 2) == [0x03e00008, 0]
for address in (0x152000, 0x1523d8):
    instruction = words(address, 1)[0]
    assert instruction >> 26 == 3
    assert (instruction & 0x03ffffff) << 2 == 0x1391f8
table = [0x1391e8, 0x23f340, 0x23f418, 0x322e08, 0x322e18, 0x139510]
assert words(0x35ebb8, 6) == table
# These exact instructions prove t7 is zero and the conditional branch is taken
# before the jump to zero. Delay-slot ld ra does not alter t7 or the branch.
assert words(0x100388, 6) == [0x3c0f0000, 0x25ef0000, 0x11e00004,
                             0xdfbf0000, 0x08000000, 0x27bd0010]
branch_target = 0x100390 + 4 + (4 << 2)
assert branch_target == 0x1003a4

build = ROOT / 'analysis/final-mix/native-build/compiler-range-verification.json'
compiled = {row['address']: row for row in json.loads(build.read_text())}
for address in ('001391e8', '001391f8'):
    assert compiled[address]['unmodified_compiled_symbol_match']
    assert compiled[address]['compiled_symbol_size'] == compiled[address]['declared_range_size'] == 8
assert compiled['00100350']['unmodified_compiled_symbol_match']
assert compiled['00100350']['compiled_symbol_size'] == compiled['00100350']['declared_range_size'] == 92
assert words(0x2e7390, 1) == [0x080b9cea]
assert words(0x2e73a4, 1) == [0]
assert words(0x2e73a8, 1) == [0x27bdfff0]
assert words(0x2e73d0, 2) == [0x03e00008, 0x27bd0010]

# A delay-slot instruction can also be a direct loop entry. Ghidra reports
# overlapping instruction contexts even though the original words are aligned
# and valid in both contexts. Preserve the warning, and record the two paths.
overlap_sites = [
    ('0020f338', 0x20f55c, 0x20f5d4),
    ('00212338', 0x212580, 0x21262c),
    ('00213ea8', 0x2140c4, 0x21413c),
    ('00215f28', 0x216170, 0x21621c),
    ('00217d80', 0x217f9c, 0x217ff4),
    ('0021aee8', 0x21b11c, 0x21b1c8),
    ('00308a80', 0x308ad0, 0x308b1c),
]
overlap_evidence = []
for function, guard, backedge in overlap_sites:
    guard_word, slot_word = words(guard, 2)
    branch_word = words(backedge, 1)[0]
    assert guard_word >> 26 in (4, 6), 'Expected beq or blez with a delay slot'
    assert branch_word >> 26 == 7, 'Expected bgtz loop backedge'
    displacement = struct.unpack('<h', struct.pack('<H', branch_word & 0xffff))[0]
    target = backedge + 4 + displacement * 4
    assert target == guard + 4
    assert slot_word >> 26 in (9, 33, 54), 'Expected addiu, lh, or lqc2 slot'
    overlap_evidence.append({
        'function': function, 'guard_address': f'{guard:08x}',
        'guard_word': f'{guard_word:08x}', 'shared_instruction_address': f'{target:08x}',
        'shared_instruction_word': f'{slot_word:08x}',
        'loop_branch_address': f'{backedge:08x}', 'loop_branch_word': f'{branch_word:08x}',
        'classification': 'branch_delay_slot_also_used_as_loop_entry',
        'ghidra_warning_retained': True,
    })

assert words(0x100084, 1) == [0x7000ec28]  # padduw sp,zero,zero
assert words(0x1001a4, 3) == [0x2403003c, 0x0000000c, 0x0040e82d]
assert words(0x315458, 6) == [0x27bdfff0, 0xffbf0000, 0x0080f809,
                            0, 0x0c0c5510, 0]
assert words(0x315470, 6) == [0x27bdfff0, 0x3c0f0036, 0xffbf0000,
                            0x0c0c5516, 0x8de477ac, 0]
assert words(0x315488, 4) == [0x3c0f0036, 0x8de277a8, 0x03e00008, 0xade477a8]
callback_sizes = {'00315458': 24, '00315470': 20, '00315488': 16}
callback_matches = {address: compiled.get(address) for address in callback_sizes}
callback_proven = all(row is not None and row['unmodified_compiled_symbol_match']
                      and row['compiled_symbol_size'] == row['declared_range_size'] == callback_sizes[address]
                      for address, row in callback_matches.items())
layout_sizes = {line.split('\t')[0]: int(line.split('\t')[2]) for line in
                (ROOT / 'tools/kh2-reference/layout.tsv').read_text().splitlines()
                if line and not line.startswith(('#', 'addr\t'))}
main_candidates = {row['address']: row for row in (json.loads(line) for line in
                   (OUT / 'main.jsonl').read_text().splitlines())}
callback_code = main_candidates['00315458'].get('code') or ''
callback_export_restored = ('(*param_1)();' in callback_code and 'FUN_00315440();' in callback_code
                            and callback_code.index('(*param_1)();') < callback_code.index('FUN_00315440();'))
verified_switches = {}
switch_evidence = OUT / 'main-jump-table-evidence.json'
switch_application = OUT / 'main-jump-table-override-application.json'
if switch_evidence.exists() and switch_application.exists():
    evidence = json.loads(switch_evidence.read_text())
    assert evidence['summary']['executable_sha256'] == expected_hash
    bounded = {(row['function'],row['jump_address']): row for row in evidence['rows']
               if row['status'] == 'bounded_original_table_verified'}
    for application in json.loads(switch_application.read_text()):
        if not application.get('applied'): continue
        address = application['function']
        code = main_candidates[address]['code']
        assert 'Switch is manually overridden' in code
        assert 'Could not recover jumptable' not in code and 'Treating indirect jump as call' not in code
        for switch_table in application['tables']:
            proof = bounded[address,switch_table['jump_address']]
            assert proof['case_count'] == switch_table['case_count'] and proof['table_address'] == switch_table['table_address']
            table_words = words(int(proof['table_address'],16),proof['case_count'])
            assert table_words == [int(target,16) for target in proof['targets']]
        verified_switches[address] = application['tables']
if callback_proven:
    assert {address: layout_sizes[address] for address in callback_sizes} == callback_sizes
    assert {address: main_candidates[address]['body_bytes'] for address in callback_sizes} == callback_sizes
findings = {
    'executable_sha256': expected_hash,
    'return_stubs': [{'address': f'{address:08x}', 'instruction_words': ['03e00008', '00000000'],
                      'compiler_match': compiled.get(f'{address:08x}')}
                     for address in (0x1391e8, 0x1391f8)],
    'direct_calls_to_001391f8': ['00152000', '001523d8'],
    'dispatch_table': {'address': '0035ebb8', 'pointer_words': [f'{a:08x}' for a in table],
                       'classification': 'data_not_function',
                       'evidence': 'Six function pointers; constructor exports 002b3d00/002b3df8 store its address into object slot zero.'},
    '00100350': {'classification': 'infeasible_zero_target_warning',
                 'proof': 'lui t7,0; addiu t7,t7,0; beq t7,zero always takes 001003a4; jump at 00100398 cannot execute.',
                 'compiler_match': compiled['00100350'],
                 'ghidra_warning_retained': True},
    'split_002e7340': {'caller_start': '002e7340', 'caller_size': 100,
                       'padding_address': '002e73a4', 'padding_size': 4,
                       'helper_start': '002e73a8', 'helper_size': 48,
                       'proof': 'Caller tail-jumps to separate helper prologue; helper returns independently. Old 152-byte ledger range merged both.',
                       'caller_compiler_match': compiled.get('002e7340'),
                       'helper_compiler_match': compiled.get('002e73a8')},
    'startup_stack_0010001c': {
        'classification': 'explicit_startup_stack_initialization',
        'clear_sp_address': '00100084', 'clear_sp_word': '7000ec28',
        'syscall_selector_address': '001001a4', 'syscall_selector': '0000003c',
        'assign_sp_from_v0_address': '001001ac', 'assign_sp_word': '0040e82d',
        'proof': 'Entry clears sp with padduw, then assigns sp from v0 immediately after syscall selector 0x3c.',
        'ghidra_warning_retained': True,
        'limitations': ['Syscall runtime result, stack extent and startup behavior are not verified.'],
    },
    'instruction_overlaps': overlap_evidence,
    'recovered_switches': {
        'function_count': len(verified_switches),
        'functions': verified_switches,
        'evidence_file': 'main-jump-table-evidence.json',
        'application_file': 'main-jump-table-override-application.json',
        'limitations': ['Explicit overrides recover original bounds and destinations, not compiler or runtime equivalence.',
                       'Manual-override warning comments remain visible.',
                       'Cross-ledger targets still require independent function-boundary review.'],
    },
    'callback_chain_00315458': {
        'classification': 'compiler_proven_callback_split' if callback_proven else 'merged_ledger_range_and_incomplete_ghidra_body',
        'previous_ledger_size': 64, 'previous_ghidra_body_size': 16,
        'current_ledger_size': layout_sizes['00315458'],
        'current_ghidra_body_size': main_candidates['00315458']['body_bytes'],
        'instruction_blocks': [
            {'address': '00315458', 'size': 24,
             'evidence': 'Stack frame, indirect callback call, then direct call to nonreturning 00315440.'},
            {'address': '00315470', 'size': 20,
             'evidence': 'New stack frame and direct call to 00315458 with callback loaded from 003677ac.'},
            {'address': '00315484', 'size': 4, 'evidence': 'Zero padding after the call delay slot.'},
            {'address': '00315488', 'size': 16,
             'evidence': 'Independent old-value getter/setter for 003677a8 with jr ra and store delay slot.'},
        ],
        'status': ('compiler_project_boundaries_and_callback_export_verified'
                   if callback_proven and callback_export_restored else
                   'compiler_and_project_boundaries_verified' if callback_proven else
                   'pending_compiler_proof_and_project_boundary_repair'),
        'callback_export_restored': callback_export_restored,
        'compiler_matches': callback_matches,
        'limitations': [('The corrected export retains the direct termination call; inferred callback targets remain advisory.'
                         if callback_export_restored else
                         'Ghidra pseudocode for 00315458 still omits the following nonreturning call; original instructions and compiler proof are authoritative.'),
                       'Static equivalence does not verify callback registration or runtime termination behavior.'],
    },
    'limitations': ['Targeted static instruction proofs do not verify game runtime behavior.',
                    'Return-stub parameter types remain unknown.',
                    'Warning classifications are review routing, not equivalence proofs.'],
}
(OUT / 'boundary-findings.json').write_text(json.dumps(findings, indent=2) + '\n')

triage = []
for path in [OUT / 'main.jsonl', *sorted((OUT / 'iop').glob('*/main.jsonl')), OUT / 'overlays/main.jsonl']:
    for line in path.read_text(encoding='utf-8').splitlines():
        row = json.loads(line)
        warning_lines = re.findall(r'/\* WARNING:.*?\*/', row.get('code') or '', re.S)
        message = row.get('decompiler_message') or ''
        if not warning_lines and not message:
            continue
        text = '\n'.join(warning_lines) + '\n' + message
        categories = []
        for needle, label in [('bad instruction', 'bad_instruction'), ('Could not recover jumptable', 'unrecovered_jumptable'),
                              ('Type propagation algorithm not settling', 'type_propagation'),
                              ('overlap smaller symbols', 'overlapping_globals'),
                              ('Read-only address', 'memory_attributes'), ('does not return', 'nonreturning_call'),
                              ('Removing unreachable block', 'unreachable_block'),
                              ('Treating indirect jump as call', 'indirect_flow'),
                              ('stack pointer', 'stack_pointer'), ('infinite loop', 'infinite_loop'),
                              ('Switch is manually overridden', 'manual_switch_override'),
                              ('Restarted to delay deadcode', 'decompiler_restart')]:
            if needle.lower() in text.lower():
                categories.append(label)
        if re.search(r'Instruction at .* overlaps instruction', text, re.S):
            categories.append('instruction_overlap')
        if message:
            categories.append('decompiler_message')
        diagnosis = None
        if row['module'] == 'SLPM_666.75' and row['address'] == '00100350':
            diagnosis = 'infeasible_zero_target_proven_from_original_instructions'
        elif row['module'] == 'SLPM_666.75' and row['address'] == '0010001c':
            diagnosis = 'explicit_startup_stack_initialization_proven_from_original_instructions'
        elif row['module'] == 'SLPM_666.75' and row['address'] in {entry[0] for entry in overlap_sites}:
            diagnosis = 'shared_branch_delay_slot_entry_proven_from_original_instructions'
        elif row['module'] == 'SLPM_666.75' and row['address'] in verified_switches:
            diagnosis = 'original_bounded_switch_targets_recovered_via_explicit_override'
        priority = 1 if any(c in categories for c in ('bad_instruction', 'unrecovered_jumptable', 'stack_pointer', 'instruction_overlap')) else 2
        triage.append({'module': row['module'], 'address': row['address'], 'status': row['status'],
                       'categories': categories or ['unclassified_warning'], 'review_priority': priority,
                       'diagnosis': diagnosis, 'warnings': warning_lines, 'decompiler_message': message})
summary = {'warning_bearing_functions': len(triage),
           'category_counts': dict(collections.Counter(c for row in triage for c in row['categories'])),
           'diagnosed_functions': sum(row['diagnosis'] is not None for row in triage),
           'unresolved_priority_1': sum(row['review_priority'] == 1 and row['diagnosis'] is None for row in triage)}
(OUT / 'warning-triage.json').write_text(json.dumps(triage, indent=2) + '\n')
(OUT / 'warning-triage-summary.json').write_text(json.dumps(summary, indent=2) + '\n')
print(json.dumps(summary, indent=2))
