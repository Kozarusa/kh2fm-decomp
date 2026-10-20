from pathlib import Path
import json
ex=Path(__file__).resolve().parent
area=ex.parent
root=area.parents[1]
for path in [area/'README.md',root/'WORKER_BRIEF.md',area/'worker-coordination/primary-status.md']:
 text=path.read_text(encoding='utf-8')
 for old,new in [('5,677 equal-size','5,682 equal-size'),('5,681 C++','5,686 C++'),('5,702 fallback','5,697 fallback'),('2,183 staged','2,188 staged'),('all 76 recovery bundles','all 77 recovery bundles'),('verify_fm_primary_callbackaddress_checkpoint.py','verify_fm_primary_callbackreturn_checkpoint.py'),('primary-callbackaddress-checkpoint-2026-10-08.json','primary-callbackreturn-checkpoint-2026-10-08.json')]:
  text=text.replace(old,new)
 text+='\nCallbackreturn accepts five complete 52-byte ranges: 001050d8, 0016c7a0, 0016fac8, 00288be8 and 0028cc08. Capturing the original return address before the object loads reproduces the original scheduling. Independent curated probes, full build, all 77 bundles, both switches, finalization, warning audit and the current gate pass. The four-hour session has accepted 51 ranges and 3,100 instruction bytes. Positive-control census covers all eleven tracked instances; the other six were already accepted.\n'
 path.write_text(text,encoding='utf-8')
claims=area/'worker-coordination/primary-claim.json'
data=json.loads(claims.read_text())
data.update(baseline_gate='tools/kh2-audit/verify_fm_primary_callbackreturn_checkpoint.py',baseline_exact_matches=5682)
claims.write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
status=area/'worker-coordination/compiler-status.json'
data=json.loads(status.read_text())
data.update(status='idle',phase='callbackreturn-accepted',last_accepted_phase='primary-callbackreturn',coordination='Acceptance complete. Coordinate compiler ownership before another shared build.')
status.write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
progress=ex/'primary-fourhour-progress-v1.json'
data=json.loads(progress.read_text())
data['new_isolated_exact']+=['001050d8','0016c7a0','0016fac8','00288be8','0028cc08']
assert len(set(data['new_isolated_exact']))==51
data.update(accepted_exact=5682,new_instruction_bytes=3100,pending_exact=[])
progress.write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
with (ex/'primary-fourhour-blockers.md').open('a',encoding='utf-8') as output:
 output.write('\n## Acceptance runner correction\n\nThe first callbackreturn acceptance runner retained the previous callbackaddress batch name. Its 76-bundle success did not establish acceptance of the new five sources. Corrected the runner, synchronized all seven intended inputs, and reran full acceptance: 77 bundles and all five complete new ranges pass. The prior accepted native build was preserved before registration. Two PowerShell inline Python generator attempts failed quoting without modifying project state; file-based generators were used instead.\n')
