from pathlib import Path
import hashlib,json,shutil,subprocess,sys
ex=Path(__file__).resolve().parent
area=ex.parent
root=area.parents[1]
public=root.parent/'Public'
audit=public/'tools/kh2-audit'
reference=public/'tools/kh2-reference'
snapshot=area/'accepted-snapshots/2026-10-08-before-lookupswitch'
assert not snapshot.exists()
snapshot.mkdir(parents=True)
shutil.copytree(area/'native-build',snapshot/'native-build')
for name in ['functions.tsv','layout.tsv']:
 shutil.copy2(reference/name,snapshot/name)
for name in ['finish_fm_primary_matrix.py','verify_fm_native_switch_tables.py']:
 shutil.copy2(audit/name,snapshot/name)
subprocess.run([sys.executable,str(audit/'prepare_fm_continuation_acceptance.py'),'lookupswitch','floatresult','00155ee8,00155fc0'],check=True)

# Extend the existing table verifier without changing either earlier batch.
verifier=audit/'verify_fm_native_switch_tables.py'
text=verifier.read_text(encoding='utf-8')
anchor="    'switch-byte':"
assert text.count(anchor)==1
text=text.replace(anchor,"    'primary-lookupswitch': ('fm_primary_lookupswitch_recovered.cpp', [('0036b2c4', '00155ee8', 88), ('0036b2ec', '00155fc0', 80)]),\n"+anchor)
compile(text,str(verifier),'exec')
verifier.write_text(text,encoding='utf-8',newline='\n')
finish=audit/'finish_fm_primary_matrix.py'
text=finish.read_text(encoding='utf-8')
anchor="for name in ('switch-helpers', 'switch-byte'):"
assert text.count(anchor)==1
text=text.replace(anchor,"switch_batches = ['switch-helpers', 'switch-byte']\nlookup_batch_name = 'primary-' + 'lookupswitch'\nif batch == 'primary-lookupswitch':\n    switch_batches.append(lookup_batch_name)\nfor name in switch_batches:")
text=text.replace('and two switch receipts passed.', 'and {len(switch_batches)} switch receipts passed.')
compile(text,str(finish),'exec')
finish.write_text(text,encoding='utf-8',newline='\n')
gate=audit/'verify_fm_primary_lookupswitch_checkpoint.py'
text=gate.read_text(encoding='utf-8')
anchor="for name in ('switch-helpers', 'switch-byte'):"
assert text.count(anchor)==1
text=text.replace(anchor,"for name in ('switch-helpers', 'switch-byte', 'primary-lookupswitch'):")
anchor="files = [root / 'HANDOFF.md'"
assert text.count(anchor)==1
validation='''lookup_receipt = read(build / 'primary-lookupswitch-table-verification.json')
assert lookup_receipt['source_sha256'] == digest(public / 'tools/kh2-reference/src/anon/fm_primary_lookupswitch_recovered.cpp')
assert {row['original_table_address'] for row in lookup_receipt['tables']} == {'0036b2c4', '0036b2ec'}
lookup_original = (public / 'tools/kh2-reference/SLPM_666.75').read_bytes()
for row in lookup_receipt['tables']:
    assert row['size'] == 20 and row['linked_symbol_is_original_absolute_address']
    offset = int(row['original_table_address'], 16) - 0x100000 + 0x1000
    assert bytes.fromhex(row['hex']) == lookup_original[offset:offset + 20]

'''
text=text.replace(anchor,validation+anchor)
text=text.replace("files += [public / 'tools/kh2-reference/tools/build_elf.py']", "files += [public / 'tools/kh2-reference/tools/build_elf.py', public / 'tools/kh2-audit/verify_fm_native_switch_tables.py']")
compile(text,str(gate),'exec')
gate.write_text(text,encoding='utf-8',newline='\n')
sync=[dict(file=name,expected_stage_sha256=hashlib.sha256((reference/name).read_bytes()).hexdigest()) for name in ['functions.tsv','layout.tsv']]
source=ex/'fm_primary_lookupswitch_recovered.cpp'
shutil.copy2(source,reference/'src/anon'/source.name)
subprocess.run([sys.executable,str(audit/'register_fm_batch.py'),f'src/anon/{source.name}','primary-lookupswitch','--include-declared','--range-proof',str(source.with_suffix('.verification.json'))],check=True)
sync.append(dict(file=f'src/anon/{source.name}',expected_stage_sha256=None))
(area/'native-build/primary-lookupswitch-sync-inputs.json').write_text(json.dumps(sync,indent=2)+'\n',encoding='utf-8')
runner=(ex/'accept_floatresult.py').read_text(encoding='utf-8').replace('floatresult','lookupswitch')
(ex/'accept_lookupswitch.py').write_text(runner,encoding='utf-8')
