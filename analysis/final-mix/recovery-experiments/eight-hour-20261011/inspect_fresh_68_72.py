from pathlib import Path
import json,subprocess
base=Path(__file__).resolve().parent;by={r['address']:r for r in json.loads((base/'fresh-68-72-census.json').read_text())}
selected=['00106a18','0010f918','001142e0','00114328','00133938','001339d0','00136ab8','0013fec0','0014f068','001585a0','0016ac38','0016df28','0016df70','0016e000','0016e048','00171268','001712b0','00172ae0','00188fe0','00194830','001a6600','001a8450']
p=base/'fresh-68-72-selected.json';assert not p.exists();p.write_text(json.dumps(selected))
for address in selected:
 size=by[address]['bytes'];path=base/f'{address}-fresh68-72-original.txt';assert not path.exists()
 r=subprocess.run(['docker','run','--rm','--platform','linux/amd64','-v','/root/kh2fm-build:/work:ro','-w','/work','kh2-local/ps2-compiler:3.2-ee-040921-objdiff','/opt/ps2/gcc/bin/ee-objdump','-d',f'--start-address=0x{address}',f'--stop-address=0x{int(address,16)+size:x}','SLPM_666.75'],capture_output=True,text=True,check=True);path.write_text(r.stdout)
 if address in selected[:6]:print(r.stdout,flush=True)
