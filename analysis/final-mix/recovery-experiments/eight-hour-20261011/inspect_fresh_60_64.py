from pathlib import Path
import json,subprocess
base=Path(__file__).resolve().parent;rows={r['address']:r for r in json.loads((base/'fresh-60-64-census.json').read_text())}
for address in ('00123d90','00124100','00132270','001375f0','0013f608','0014f688','00153310','0015a118','0017c8f0','001b6f48','001d0068','001d4dc0'):
 size=rows[address]['bytes']
 result=subprocess.run(['docker','run','--rm','--platform','linux/amd64','-v','/root/kh2fm-build:/work:ro','-w','/work','kh2-local/ps2-compiler:3.2-ee-040921-objdiff','/opt/ps2/gcc/bin/ee-objdump','-d',f'--start-address=0x{address}',f'--stop-address=0x{int(address,16)+size:x}','SLPM_666.75'],capture_output=True,text=True,check=True)
 path=base/f'{address}-fresh60-64-original.txt';assert not path.exists();path.write_text(result.stdout);print(result.stdout)
