from pathlib import Path
import json,subprocess
base=Path(__file__).resolve().parent;rows={r['address']:r for r in json.loads((base/'fresh-60-64-census.json').read_text())}
selected={'0015a6c8':64,'002314c0':60,'002424c0':60,'00242980':64,'002429c0':60,'00287720':64,'00287760':64,'0029e258':60,'0029e3a0':60,'002b7f84':56,'002b6b84':64}
for address,size in selected.items():
 result=subprocess.run(['docker','run','--rm','--platform','linux/amd64','-v','/root/kh2fm-build:/work:ro','-w','/work','kh2-local/ps2-compiler:3.2-ee-040921-objdiff','/opt/ps2/gcc/bin/ee-objdump','-d',f'--start-address=0x{address}',f'--stop-address=0x{int(address,16)+size:x}','SLPM_666.75'],capture_output=True,text=True,check=True)
 path=base/f'{address}-fresh-context-original.txt';assert not path.exists();path.write_text(result.stdout);print(result.stdout)
