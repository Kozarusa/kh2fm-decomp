from pathlib import Path
import subprocess
w=Path("/mnt/c/Users/KoZa/Documents/AGENTS/Codex");a=w.parent/"Public/tools/kh2-audit";s=Path("/root/kh2fm-build");base=Path(__file__).resolve().parent
subprocess.run(["python3",str(a/"sync_fm_boundary_checkpoint.py"),str(base/"queuekappaprime-tool-sync.json")],check=True)
cache=s/"out/generated/normalize_cache.json";archive=s/"out/alignment-diagnostic/normalize-cache-before-repair.json";assert not archive.exists();cache.rename(archive)
with (w/"analysis/final-mix/native-build/primary-queuekappaprime-alignment-retry-make-verify.log").open("x") as log:
 subprocess.run(["make","verify","MAKE_JOBS=8"],cwd=s,stdout=log,stderr=subprocess.STDOUT,check=True)
subprocess.run(["python3",str(a/"finish_fm_primary_matrix.py"),"primary-queuekappaprime"],check=True)
