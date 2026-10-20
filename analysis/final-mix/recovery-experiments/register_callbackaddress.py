from pathlib import Path
import hashlib,json,shutil,subprocess,sys
ex=Path(__file__).resolve().parent
area=ex.parent
root=area.parents[1]
public=root.parent/'Public'
audit=public/'tools/kh2-audit'
reference=public/'tools/kh2-reference'
snapshot=area/'accepted-snapshots/2026-10-08-before-callbackaddress'
assert not snapshot.exists()
snapshot.mkdir(parents=True)
shutil.copytree(area/'native-build',snapshot/'native-build')
for name in ['functions.tsv','layout.tsv']:
 shutil.copy2(reference/name,snapshot/name)
shutil.copy2(audit/'finish_fm_primary_matrix.py',snapshot/'finish_fm_primary_matrix.py')
addresses=['001dc488','001de948','001e0128','001e0188']
sources=[f'analysis/final-mix/recovery-experiments/fm_primary_callbackaddress_recovered_{a}.cpp' for a in addresses]
bundle=ex/'callbackaddress-curated-inputs.json'
bundle.write_text(json.dumps(sources,indent=2)+'\n',encoding='utf-8')
subprocess.run([sys.executable,str(audit/'prepare_fm_continuation_acceptance.py'),'callbackaddress','floatiterator',','.join(addresses),str(bundle)],check=True)
sync=[dict(file=n,expected_stage_sha256=hashlib.sha256((reference/n).read_bytes()).hexdigest()) for n in ['functions.tsv','layout.tsv']]
for relative,address in zip(sources,addresses):
 source=root/relative
 destination=reference/'src/anon'/source.name
 shutil.copy2(source,destination)
 subprocess.run([sys.executable,str(audit/'register_fm_batch.py'),f'src/anon/{source.name}',f'primary-callbackaddress-{address}','--include-declared','--range-proof',str(source.with_suffix('.verification.json'))],check=True)
 sync.append(dict(file=f'src/anon/{source.name}',expected_stage_sha256=None))
(area/'native-build/primary-callbackaddress-sync-inputs.json').write_text(json.dumps(sync,indent=2)+'\n',encoding='utf-8')
runner=(ex/'accept_floatiterator.py').read_text(encoding='utf-8').replace('floatiterator','callbackaddress')
(ex/'accept_callbackaddress.py').write_text(runner,encoding='utf-8')
