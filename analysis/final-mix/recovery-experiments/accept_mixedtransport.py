from pathlib import Path
import subprocess
workspace=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex')
audit=workspace.parent/'Public/tools/kh2-audit'
stage=Path('/root/kh2fm-build')
subprocess.run(['python3',str(audit/'sync_fm_boundary_checkpoint.py'),str(workspace/'analysis/final-mix/native-build/primary-mixedtransport-sync-inputs.json')],check=True)
with (workspace/'analysis/final-mix/native-build/primary-mixedtransport-make-verify.log').open('w') as log:
 subprocess.run(['make','verify','MAKE_JOBS=8'],cwd=stage,stdout=log,stderr=subprocess.STDOUT,check=True)
subprocess.run(['python3',str(audit/'finish_fm_primary_matrix.py'),'primary-mixedtransport'],check=True)
