"""Verify the new recovery checkpoint against its prior saved session and proofs."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys

root = Path(__file__).resolve().parents[2]
analysis = root / 'analysis/final-mix'
build = analysis / 'native-build'
experiments = analysis / 'recovery-experiments'

def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

def read(path):
    return json.loads(path.read_text())

prior = read(analysis / 'primary-workerthree-checkpoint-2026-10-07.json')
assert prior['active_exact_matches'] == 5480
artifacts = read(build / 'artifact-manifest.json')
for row in artifacts:
    path = build / row['file']
    assert path.stat().st_size == row['size'] and digest(path) == row['sha256']
provenance = read(build / 'build-input-provenance.json')
for row in provenance:
    assert digest(root / 'tools/kh2-reference' / row['file']) == row['sha256']
summary = read(build / 'native-build-verification.json')
assert summary == read(analysis / 'native-pseudocode/combined-summary.json')['main_cpp_build_checkpoint']
assert summary['source_input_files_verified_against_workspace'] == len(provenance)
assert summary['whole_executable_byte_exact']
assert summary['rebuilt_sha256'] == digest(build / 'kh2.elf') == summary['original_sha256']
records = read(build / 'compiler-range-verification.json')
assert len(records) == summary['cpp_range_count']
assert len({row['address'] for row in records}) == len(records)
assert all(row['normalized_match'] and row['size_status'] != 'truncated' for row in records)
assert summary['compiler_size_status_counts'] == {
    'equal_size': summary['unmodified_compiled_symbol_matches'], 'zero_padded': 4}
assert {row['address'] for row in records if row['size_status'] == 'zero_padded'} == {
    '0018f9f8', '0014f148', '00168370', '00315440'}

bundles = [('scalar-curated-bundle', 168), ('scalar-extra-curated-bundle', 35),
           ('autonomous-curated-bundle', 112), ('followup-complete-bundle', 44), ('last-window-curated-bundle', 4), ('oct7-complete-curated-bundle', 4), ('oct7-clamp-curated-bundle', 2), ('primary-matrix-curated-bundle', 1), ('worker-b-initializers-curated-bundle', 4), ('primary-resume-curated-bundle', 10), ('primary-width-curated-bundle', 25), ('primary-near-curated-bundle', 5), ('primary-close-curated-bundle', 3), ('primary-transport-curated-bundle', 4), ('primary-schedule-curated-bundle', 1), ('primary-argument-curated-bundle', 4), ('primary-structure-curated-bundle', 3), ('primary-packet-curated-bundle', 1), ('primary-animation-curated-bundle', 3), ('primary-floatload-curated-bundle', 1), ('primary-oneword-curated-bundle', 18), ('primary-twoword-curated-bundle', 13), ('primary-twowordnext-curated-bundle', 10), ('primary-order-curated-bundle', 2), ('primary-threeword-curated-bundle', 12), ('primary-transportnext-curated-bundle', 2), ('primary-addresspair-curated-bundle', 2), ('primary-floatpacket-curated-bundle', 1), ('primary-threewordnext-curated-bundle', 3), ('primary-capacity-curated-bundle', 1), ('primary-fourword-curated-bundle', 6), ('primary-workertwo-curated-bundle', 4), ('primary-twowordfresh-curated-bundle', 6), ('primary-clearsequence-curated-bundle', 1), ('primary-fourwordfresh-curated-bundle', 7), ('primary-fourwordnext-curated-bundle', 1), ('primary-fiveword-curated-bundle', 7), ('primary-sixword-curated-bundle', 9), ('primary-sixwordnext-curated-bundle', 4), ('primary-workerthree-curated-bundle', 3), ('primary-floatarguments-curated-bundle', 1)]
selected = set()
for name, count in bundles:
    receipt = read(build / f'{name}-verification.json')
    assert receipt['exact_functions'] == count
    assert receipt['compiler_records_sha256'] == digest(build / 'compiler-range-verification.json')
    assert receipt['linked_elf_sha256'] == digest(build / 'linked.tmp.elf')
    assert receipt['bundle_sha256'] == digest(root / receipt['bundle'])
    for group in receipt['groups']:
        assert digest(root / 'tools/kh2-reference' / group['source']) == group['source_sha256']
        proof_path = experiments / (Path(group['source']).stem + '.verification.json')
        assert digest(proof_path) == group['probe_proof_sha256']
        proof = read(proof_path)
        assert proof['source_sha256'] == digest(proof_path.with_suffix('').with_suffix('.cpp'))
        assert all(row['exact_match'] and row['compiled_hex'] == row['target_hex']
                   and row['compiled_size'] == row['target_size'] for row in proof['rows'])
        assert set(group['addresses']) == {row['address'] for row in proof['rows']}
        if name == 'primary-floatarguments-curated-bundle':
            assert not selected & set(group['addresses'])
            selected.update(group['addresses'])
assert selected == {'0018f9b8'}
assert summary['unmodified_compiled_symbol_matches'] == prior['active_exact_matches'] + len(selected)
for name in ('switch-helpers', 'switch-byte'):
    receipt = read(build / f'{name}-table-verification.json')
    assert receipt['linked_elf_sha256'] == digest(build / 'linked.tmp.elf')
    assert all(row['generated_data_exact_match'] for row in receipt['tables'])
subprocess.run([sys.executable, str(root / 'tools/kh2-audit/verify_fm_switch_probe.py')], check=True)

subprocess.run([sys.executable, str(root / 'tools/kh2-audit/verify_fm_callback_flow.py')], check=True)

files = [root / 'HANDOFF.md', analysis / 'README.md', experiments / 'README.md',
         analysis / 'usage-floor-checkpoint-2026-10-06.json', build / 'artifact-manifest.json',
         analysis / 'native-pseudocode/combined-summary.json',
         analysis / 'native-pseudocode/warning-triage-summary.json']
files += [root / 'tools/kh2-audit' / name for name in (
    'curate_fm_probe.py', 'generate_fm_return_variants.py', 'generate_fm_width_variants.py',
    'verify_fm_primary_floatarguments_checkpoint.py', 'prepare_fm_continuation_acceptance.py', 'prepare_fm_near_dependency_retry.py', 'rank_fm_primary_near_matches.py', 'generate_fm_primary_width_probes.py', 'curate_fm_primary_width_bundle.py', 'verify_fm_callback_flow.py', 'prepare_fm_matrix_retry.py', 'finish_fm_primary_matrix.py', 'generate_fm_call_variants.py',
    'generate_fm_global_probes.py', 'generate_fm_float_roles.py', 'generate_fm_extended_probes.py')]
files += [root / 'analysis/final-mix/worker-coordination/worker-b/recovered' / name for name in (
    'fm_worker_b_recovered_exact.cpp', 'fm_worker_b_recovered_exact.verification.json')]
files += [analysis / 'native-pseudocode' / name for name in (
    'main.jsonl', 'callback-flow-merge-v1.json', 'callback-flow-merge-v2.json',
    'callback-flow-compiler-records-v1.json', 'callback-flow-reopened-v1.txt')]
files += [path for path in experiments.iterdir() if path.is_file() and path.name.startswith((
    'fm_resume_', 'fm_return_variants', 'fm_width_', 'fm_memory_', 'fm_small_resume_',
    'return-variants', 'width-', 'resume-curated', 'autonomous-curated',
    'fm_constructor_', 'fm_small_retry', 'fm_global_', 'fm_float_', 'fm_call_fixed_',
    'constructor-retry-', 'followup-', 'global-', 'fixed-call-', 'float-',
    'fm_last_window_', 'last-window-', 'fm_oct7_', 'oct7-', 'fm_primary_matrix', 'primary-matrix-', 'fm_worker_b', 'worker-b-', 'fm_primary_resume', 'primary-resume-', 'fm_primary_width', 'primary-width-', 'fm_primary_near', 'primary-near-', 'fm_primary_close', 'primary-close-', 'fm_primary_transport', 'primary-transport-', 'fm_primary_schedule', 'primary-schedule-', 'fm_primary_argument', 'primary-argument-', 'fm_primary_structure', 'primary-structure-', 'fm_primary_packet', 'primary-packet-', 'fm_primary_animation', 'primary-animation-', 'fm_primary_floatload', 'primary-floatload-', 'fm_primary_oneword', 'primary-oneword-', 'fm_primary_twoword', 'primary-twoword-', 'fm_primary_twowordnext', 'primary-twowordnext-', 'fm_primary_order', 'primary-order-', 'fm_primary_threeword', 'primary-threeword-', 'fm_primary_transportnext', 'primary-transportnext-', 'fm_primary_addresspair', 'primary-addresspair-', 'fm_primary_floatpacket', 'primary-floatpacket-', 'fm_primary_threewordnext', 'primary-threewordnext-', 'fm_primary_capacity', 'primary-capacity-', 'fm_primary_fourword', 'primary-fourword-', 'fm_primary_workertwo', 'primary-workertwo-', 'fm_primary_twowordfresh', 'primary-twowordfresh-', 'fm_primary_clearsequence', 'primary-clearsequence-', 'fm_primary_fourwordfresh', 'primary-fourwordfresh-', 'fm_primary_fourwordnext', 'primary-fourwordnext-', 'fm_primary_fiveword', 'primary-fiveword-', 'fm_primary_sixword', 'primary-sixword-', 'fm_primary_sixwordnext', 'primary-sixwordnext-', 'fm_primary_workerthree', 'primary-workerthree-', 'fm_primary_floatarguments', 'primary-floatarguments-'))]
files += [path for path in build.iterdir() if path.is_file() and path.suffix == '.json'
          and path.name.startswith(('resume-', 'width-', 'small-resume-', 'autonomous-', 'scalar-',
                                    'followup-', 'global-', 'float-memory-', 'last-window-', 'oct7-', 'primary-matrix-', 'worker-b-', 'primary-resume-', 'primary-width-', 'primary-near-', 'primary-close-', 'primary-transport-', 'primary-schedule-', 'primary-argument-', 'primary-structure-', 'primary-packet-', 'primary-animation-', 'primary-floatload-', 'primary-oneword-', 'primary-twoword-', 'primary-twowordnext-', 'primary-order-', 'primary-threeword-', 'primary-transportnext-', 'primary-addresspair-', 'primary-floatpacket-', 'primary-threewordnext-', 'primary-capacity-', 'primary-fourword-', 'primary-workertwo-', 'primary-twowordfresh-', 'primary-clearsequence-', 'primary-fourwordfresh-', 'primary-fourwordnext-', 'primary-fiveword-', 'primary-sixword-', 'primary-sixwordnext-', 'primary-workerthree-', 'primary-floatarguments-'))]
receipt = {
    'session': '2026-10-07-primary-floatarguments', 'status': 'saved',
    'baseline_exact_matches': prior['active_exact_matches'],
    'active_exact_matches_added': len(selected),
    'active_exact_matches': summary['unmodified_compiled_symbol_matches'],
    'local_recovery_additions': prior['local_recovery_additions'] + len(selected),
    'source_inputs_checked': len(provenance), 'native_artifacts_checked': len(artifacts),
    'future_handoff_resume_authorized': True,
    'limitations': summary['limitations'] + ['Source types and callee prototypes remain provisional.'],
    'files': [{'file': path.relative_to(root).as_posix(), 'size': path.stat().st_size,
               'sha256': digest(path)} for path in sorted(set(files))],
}
(analysis / 'primary-floatarguments-checkpoint-2026-10-07.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(f'Primary floatarguments checkpoint PASS: +{len(selected)} exact functions, '
      f'{summary["unmodified_compiled_symbol_matches"]} total, '
      f'{len(provenance)} inputs.')

