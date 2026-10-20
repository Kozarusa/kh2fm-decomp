from pathlib import Path
import hashlib,json,shutil,subprocess,sys
ex=Path(__file__).resolve().parent
area=ex.parent
root=area.parents[1]
public=root.parent/'Public'
audit=public/'tools/kh2-audit'
reference=public/'tools/kh2-reference'
snapshot=area/'accepted-snapshots/2026-10-08-before-indexedmask'
assert not snapshot.exists()
snapshot.mkdir(parents=True)
shutil.copytree(area/'native-build',snapshot/'native-build')
for name in ['functions.tsv','layout.tsv']:
 shutil.copy2(reference/name,snapshot/name)
shutil.copy2(audit/'finish_fm_primary_matrix.py',snapshot/'finish_fm_primary_matrix.py')
addresses=['001584a0']
sources=[f'analysis/final-mix/recovery-experiments/fm_primary_indexedmask_recovered_{a}.cpp' for a in addresses]
bundle=ex/'indexedmask-curated-inputs.json'
bundle.write_text(json.dumps(sources,indent=2)+'\n',encoding='utf-8')
subprocess.run([sys.executable,str(audit/'prepare_fm_continuation_acceptance.py'),'indexedmask','lookupswitch',','.join(addresses),str(bundle)],check=True)
sync=[dict(file=n,expected_stage_sha256=hashlib.sha256((reference/n).read_bytes()).hexdigest()) for n in ['functions.tsv','layout.tsv']]
for relative,address in zip(sources,addresses):
 source=root/relative
 destination=reference/'src/anon'/source.name
 shutil.copy2(source,destination)
 subprocess.run([sys.executable,str(audit/'register_fm_batch.py'),f'src/anon/{source.name}',f'primary-indexedmask-{address}','--include-declared','--range-proof',str(source.with_suffix('.verification.json'))],check=True)
 sync.append(dict(file=f'src/anon/{source.name}',expected_stage_sha256=None))
(area/'native-build/primary-indexedmask-sync-inputs.json').write_text(json.dumps(sync,indent=2)+'\n',encoding='utf-8')
runner=(ex/'accept_lookupswitch.py').read_text(encoding='utf-8').replace('lookupswitch','indexedmask')
(ex/'accept_indexedmask.py').write_text(runner,encoding='utf-8')
