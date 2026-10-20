from pathlib import Path
import subprocess
base=Path(__file__).resolve().parent;w=base.parents[3];audit=w.parent/'Public/tools/kh2-audit';stage=Path('/root/kh2fm-build')
subprocess.run(['python3',str(audit/'sync_fm_boundary_checkpoint.py'),str(base/'queuelambdaprime-scoped-tool-sync.json')],check=True)
with (w/'analysis/final-mix/native-build/primary-queuelambdaprime-scoped-guard-retry-make-verify.log').open('x') as log:
 subprocess.run(['make','verify','MAKE_JOBS=8'],cwd=stage,stdout=log,stderr=subprocess.STDOUT,check=True)
subprocess.run(['python3',str(audit/'finish_fm_primary_matrix.py'),'primary-queuelambdaprime'],check=True)
