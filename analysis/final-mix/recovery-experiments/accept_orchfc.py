from pathlib import Path
import subprocess
w=Path("/mnt/c/Users/KoZa/Documents/AGENTS/Codex")
a=w.parent/"Public/tools/kh2-audit"
s=Path("/root/kh2fm-build")
subprocess.run(["python3",str(a/"sync_fm_boundary_checkpoint.py"),str(w/"analysis/final-mix/native-build/primary-orchfc-sync-inputs.json")],check=True)
with (w/"analysis/final-mix/native-build/primary-orchfc-make-verify.log").open("w") as log:
 subprocess.run(["make","verify","MAKE_JOBS=8"],cwd=s,stdout=log,stderr=subprocess.STDOUT,check=True)
subprocess.run(["python3",str(a/"finish_fm_primary_matrix.py"),"primary-orchfc"],check=True)
