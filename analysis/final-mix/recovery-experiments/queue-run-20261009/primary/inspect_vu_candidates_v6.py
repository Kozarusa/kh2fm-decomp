import subprocess,json
from pathlib import Path
w=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex')
area=w/'analysis/final-mix'
rows={r['address']:r for r in json.loads((area/'project-prioritized-range-backlog.json').read_text())['ordered_ranges']}
output=[]
for address in ['00163828','00153540','002c18e0','00146cb0','00162bb0','0017d160','0018a4d8','002f4028']:
 r=rows[address]
 result=subprocess.run(['docker','run','--rm','--platform','linux/amd64','-v','/root/kh2fm-build:/work','-w','/work','kh2-local/ps2-compiler:3.2-ee-040921-objdiff','/opt/ps2/gcc/bin/ee-objdump','-d','-z','--start-address=0x'+address,'--stop-address=0x'+r['end'],'SLPM_666.75'],capture_output=True,text=True,check=True)
 output.append(result.stdout)
text='\n'.join(output)
(area/'recovery-experiments/queue-run-20261009/primary/vu-next-original-disassembly-v6.txt').write_text(text)
print(text)

