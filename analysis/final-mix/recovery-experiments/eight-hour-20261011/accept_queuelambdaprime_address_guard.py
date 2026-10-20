from pathlib import Path
import subprocess
base=Path(__file__).resolve().parent;w=base.parents[3];audit=w.parent/'Public/tools/kh2-audit'
subprocess.run(['python3',str(audit/'sync_fm_boundary_checkpoint.py'),str(base/'queuelambdaprime-tool-sync.json')],check=True)
subprocess.run(['python3',str(base.parent/'accept_queuelambdaprime.py')],check=True)
