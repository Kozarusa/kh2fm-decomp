from pathlib import Path
import json,subprocess
base=Path(__file__).resolve().parent
for row in json.loads((base/'sdk-larger-frame-census.json').read_text()):
 if row['bytes'] not in (56,72,80,88,96,104,112,120,128):continue
 address=row['address'];size=row['bytes'];p=base/f'{address}-SDK-larger-original.txt';assert not p.exists()
 result=subprocess.run(['docker','run','--rm','--platform','linux/amd64','-v','/root/kh2fm-build:/work:ro','-w','/work','kh2-local/ps2-compiler:3.2-ee-040921-objdiff','/opt/ps2/gcc/bin/ee-objdump','-d',f'--start-address=0x{address}',f'--stop-address=0x{int(address,16)+size:x}','SLPM_666.75'],capture_output=True,text=True,check=True);p.write_text(result.stdout)
 if address in ('002b6adc','002b6f28','002b7d5c','002b823c'):print(result.stdout,flush=True)
