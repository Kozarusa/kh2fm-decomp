from pathlib import Path
import json,subprocess
base=Path(__file__).resolve().parent;by={r['address']:r for r in json.loads((base/'fresh-76-84-census.json').read_text())}
selected=['00106a60','0010cce0','00138140','00160488','00161548','00161598','0016bd10','0016c358','0016d640','0016d8d0','0016e240','0016ffc8','00170ee8','00171518','00171640','00172890','00173558','00173dc0','00175b68','00176818','0017a6c8','0018dbd8','0018f0b0','00192818']
p=base/'fresh-76-84-selected.json';assert not p.exists();p.write_text(json.dumps(selected))
for address in selected:
 size=by[address]['bytes'];path=base/f'{address}-fresh76-84-original.txt';assert not path.exists()
 r=subprocess.run(['docker','run','--rm','--platform','linux/amd64','-v','/root/kh2fm-build:/work:ro','-w','/work','kh2-local/ps2-compiler:3.2-ee-040921-objdiff','/opt/ps2/gcc/bin/ee-objdump','-d',f'--start-address=0x{address}',f'--stop-address=0x{int(address,16)+size:x}','SLPM_666.75'],capture_output=True,text=True,check=True);path.write_text(r.stdout)
 if address in ('00106a60','0010cce0','00160488','0016d640','0016d8d0'):print(r.stdout,flush=True)
