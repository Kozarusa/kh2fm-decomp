from pathlib import Path
import json
ex=Path(__file__).resolve().parent
area=ex.parent
root=area.parents[1]
for path in [area/'README.md',root/'WORKER_BRIEF.md',area/'worker-coordination/primary-status.md']:
 text=path.read_text(encoding='utf-8')
 for old,new in [('5,673 equal-size','5,677 equal-size'),('5,677 C++','5,681 C++'),('5,706 fallback','5,702 fallback'),('2,179 staged','2,183 staged'),('75 recovery bundles','76 recovery bundles'),('all 75 bundles','all 76 bundles'),('verify_fm_primary_floatiterator_checkpoint.py','verify_fm_primary_callbackaddress_checkpoint.py'),('primary-floatiterator-checkpoint-2026-10-08.json','primary-callbackaddress-checkpoint-2026-10-08.json')]:
  text=text.replace(old,new)
 text+='\nCallbackaddress accepts four complete 48-byte ranges: 001dc488, 001de948, 001e0128 and 001e0188. Signed low offsets establish globals 01d5bb00 and 01d9e340; earlier proposals decoded these incorrectly. Curated independent probes, full build, all 76 cumulative bundles, both switches, finalization, warning audit and current gate passed. The four-hour session has accepted 46 ranges and 2,840 instruction bytes. The positive-control machine census finds exactly these four instances of this instruction family.\n'
 path.write_text(text,encoding='utf-8')
claims=area/'worker-coordination/primary-claim.json'
data=json.loads(claims.read_text())
data['baseline_gate']='tools/kh2-audit/verify_fm_primary_callbackaddress_checkpoint.py'
data['baseline_exact_matches']=5677
claims.write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
status=area/'worker-coordination/compiler-status.json'
data=json.loads(status.read_text())
data.update(status='idle',phase='callbackaddress-accepted',last_accepted_phase='primary-callbackaddress',coordination='Acceptance complete. Coordinate compiler ownership before another shared build.')
status.write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
progress=ex/'primary-fourhour-progress-v1.json'
data=json.loads(progress.read_text())
print(data['new_isolated_exact'][-1])
for address in ['001dc488','001de948','001e0128','001e0188']:
 data['new_isolated_exact'].append(dict(address=address,bytes=48))
data.update(accepted_exact=5677,new_instruction_bytes=2840,pending_exact=[])
progress.write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
blockers=ex/'primary-fourhour-blockers.md'
with blockers.open('a',encoding='utf-8') as output:
 output.write('\n## Epilogue family follow-up\n\nFive register/lifetime marker variants each for 0014dc48, 0014dca8 and 002e5f70 failed exact comparison. The first two remain equal-size with saved-register restore order differences; a $17 clobber expands 002e5f70 to 76 bytes against 68. Preserved proposals and proof files use fm_primary_epiloguefamily_v1. Parked these three targets and moved to callbacks. Four callbacks from the same exploratory batch were subsequently resolved and fully accepted by callbackaddress; corrected global addresses and fixed original register transports were necessary.\n')
