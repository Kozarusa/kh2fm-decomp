import subprocess,json
from pathlib import Path
workspace=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex')
area=workspace/'analysis/final-mix'
rows={r['address']:r for r in json.loads((area/'project-prioritized-range-backlog.json').read_text())['ordered_ranges']}
output=[]
for address in ['00203a40','00207260','00209fb8','0020b410','00178cf8','002f3d08','002f47d8','00222568']:
 r=rows[address]
 result=subprocess.run(['docker','run','--rm','--platform','linux/amd64','-v','/root/kh2fm-build:/work','-w','/work','kh2-local/ps2-compiler:3.2-ee-040921-objdiff','/opt/ps2/gcc/bin/ee-objdump','-d','--start-address=0x'+address,'--stop-address=0x'+r['end'],'SLPM_666.75'],capture_output=True,text=True,check=True)
 output.append(result.stdout)
text='\n'.join(output)
(area/'recovery-experiments/queue-run-20261009/primary/vu-next-original-disassembly-v2.txt').write_text(text)
print(text)
