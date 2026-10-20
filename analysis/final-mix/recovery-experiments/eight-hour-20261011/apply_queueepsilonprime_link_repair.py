"""Replace one unaccepted source with an independently proven symbol repair."""
from pathlib import Path
import hashlib,json,shutil,subprocess,sys
base=Path(__file__).resolve().parent;workspace=base.parents[3];root=workspace.parent;reference=root/'Public/tools/kh2-reference';ex=base.parent
old_name='fm_primary_queueepsilonprime_recovered_001394d8.cpp';new_name='fm_primary_queueepsilonprime_repaired_001394d8.cpp'
old_relative=f'analysis/final-mix/recovery-experiments/{old_name}';new_relative=f'analysis/final-mix/recovery-experiments/{new_name}'
old_registered=reference/'src/anon'/old_name;new_source=ex/new_name;new_registered=reference/'src/anon'/new_name
proof=json.loads(new_source.with_suffix('.verification.json').read_text());assert proof['source_sha256']==hashlib.sha256(new_source.read_bytes()).hexdigest();assert len(proof['rows'])==1 and proof['rows'][0]['exact_match']
archive=base/'queueepsilonprime-pre-repair-registered.cpp';assert not archive.exists() and not new_registered.exists()
assert old_registered.resolve().is_relative_to(reference.resolve()) and archive.resolve().is_relative_to(root.resolve())
updates=[]
for name in ('queueepsilonprime-curated-inputs.json','primary-queueepsilonprime-curated-bundle.json','queueepsilonprime-queue-submissions.json'):
 path=ex/name;backup=base/(name+'.before-link-repair');assert not backup.exists();data=json.loads(path.read_text())
 if name.endswith('submissions.json'):
  selected=[r for r in data if r['address']=='001394d8'];assert len(selected)==1 and selected[0]['curated']==old_relative;selected[0]['curated']=new_relative
 else:
  assert data.count(old_relative)==1;data=[new_relative if r==old_relative else r for r in data]
 updates.append((path,backup,data))
old_hash=hashlib.sha256(old_registered.read_bytes()).hexdigest()
old_registered.rename(archive);shutil.copy2(new_source,new_registered)
for path,backup,data in updates:
 shutil.copy2(path,backup);path.write_text(json.dumps(data,indent=2)+'\n')
subprocess.run([sys.executable,str(root/'Public/tools/kh2-audit/register_fm_batch.py'),f'src/anon/{new_name}','primary-queueepsilonprime-001394d8-repair','--include-declared','--range-proof',str(new_source.with_suffix('.verification.json'))],check=True)
manifest=json.loads((workspace/'analysis/final-mix/native-build/primary-queueepsilonprime-sync-inputs.json').read_text())
assert sum(r['file']==f'src/anon/{old_name}' for r in manifest)==1
for row in manifest:
 if row['file']==f'src/anon/{old_name}':row.update(file=f'src/anon/{new_name}',expected_stage_sha256=None)
sync=workspace/'analysis/final-mix/native-build/primary-queueepsilonprime-repair-sync-inputs.json';assert not sync.exists();sync.write_text(json.dumps(manifest,indent=2)+'\n')
receipt={'address':'001394d8','reason':'The legacy assembly definition of func_00139768 resolves to temporary linked text and shadows the address PROVIDE. A distinct typed function alias D_00139768 resolves absolutely to 00139768.','old_registered_sha256':old_hash,'archived_registered_source':archive.relative_to(workspace).as_posix(),'new_registered_source':f'src/anon/{new_name}','new_source_sha256':hashlib.sha256(new_registered.read_bytes()).hexdigest(),'new_proof_sha256':hashlib.sha256(new_source.with_suffix('.verification.json').read_bytes()).hexdigest(),'stage_old_source':f'src/anon/{old_name}','stage_archive':f'out/rejected/{old_name}','sync_manifest':sync.relative_to(workspace).as_posix(),'failed_full_elf':'queueepsilonprime-failed-full.elf','prior_receipts':[backup.relative_to(workspace).as_posix() for _,backup,_ in updates]}
receipt_path=base/'queueepsilonprime-link-repair.json';assert not receipt_path.exists();receipt_path.write_text(json.dumps(receipt,indent=2)+'\n')
runner=base/'accept_queueepsilonprime_repair.py';assert not runner.exists()
runner.write_text('from pathlib import Path\nimport hashlib,json,subprocess\nbase=Path(__file__).resolve().parent\nw=base.parents[3]\ns=Path("/root/kh2fm-build")\na=w.parent/"Public/tools/kh2-audit"\nr=json.loads((base/"queueepsilonprime-link-repair.json").read_text())\nold=s/r["stage_old_source"];archive=s/r["stage_archive"]\nassert old.resolve().is_relative_to(s.resolve()) and archive.resolve().is_relative_to((s/"out").resolve())\nassert hashlib.sha256(old.read_bytes()).hexdigest()==r["old_registered_sha256"]\nassert not archive.exists();archive.parent.mkdir(parents=True,exist_ok=True);old.rename(archive)\nsubprocess.run(["python3",str(a/"sync_fm_boundary_checkpoint.py"),str(w/r["sync_manifest"])],check=True)\nwith (base/"queueepsilonprime-repair-make-verify.log").open("x") as log:\n subprocess.run(["make","verify","MAKE_JOBS=8"],cwd=s,stdout=log,stderr=subprocess.STDOUT,check=True)\nsubprocess.run(["python3",str(a/"finish_fm_primary_matrix.py"),"primary-queueepsilonprime"],check=True)\n')
print('Repaired one source; prior source, failed ELF and receipts retained. Full acceptance still required.')
