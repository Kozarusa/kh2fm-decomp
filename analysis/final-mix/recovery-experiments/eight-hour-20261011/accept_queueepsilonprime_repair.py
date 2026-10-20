from pathlib import Path
import hashlib,json,subprocess
base=Path(__file__).resolve().parent
w=base.parents[3]
s=Path("/root/kh2fm-build")
a=w.parent/"Public/tools/kh2-audit"
r=json.loads((base/"queueepsilonprime-link-repair.json").read_text())
old=s/r["stage_old_source"];archive=s/r["stage_archive"]
assert old.resolve().is_relative_to(s.resolve()) and archive.resolve().is_relative_to((s/"out").resolve())
assert hashlib.sha256(old.read_bytes()).hexdigest()==r["old_registered_sha256"]
assert not archive.exists();archive.parent.mkdir(parents=True,exist_ok=True);old.rename(archive)
subprocess.run(["python3",str(a/"sync_fm_boundary_checkpoint.py"),str(w/r["sync_manifest"])],check=True)
with (base/"queueepsilonprime-repair-make-verify.log").open("x") as log:
 subprocess.run(["make","verify","MAKE_JOBS=8"],cwd=s,stdout=log,stderr=subprocess.STDOUT,check=True)
subprocess.run(["python3",str(a/"finish_fm_primary_matrix.py"),"primary-queueepsilonprime"],check=True)
