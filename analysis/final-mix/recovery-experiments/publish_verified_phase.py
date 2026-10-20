from pathlib import Path
import csv,json,re,sys
ex=Path(__file__).resolve().parent
area=ex.parent
root=area.parents[1]
phase,old_phase=sys.argv[1:3]
current_path=sorted(area.glob(f'primary-{phase}-checkpoint-*.json'))[-1]
old_path=sorted(area.glob(f'primary-{old_phase}-checkpoint-*.json'))[-1]
current=json.loads(current_path.read_text())
old=json.loads(old_path.read_text())
bundle=json.loads((ex/f'primary-{phase}-curated-bundle.json').read_text())
rows=[r for source in bundle for r in json.loads((root/source).with_suffix('.verification.json').read_text())['rows']]
assert all(r['exact_match'] and r['compiled_size']==r['target_size'] for r in rows)
assert len(rows)==current['active_exact_matches_added']
layout=root.parent/'Public/tools/kh2-reference/layout.tsv'
total=len(list(csv.DictReader((line for line in layout.read_text().splitlines() if not line.startswith('#')),delimiter='\t')))
old_exact=old['active_exact_matches'];new_exact=current['active_exact_matches']
progress_path=ex/'primary-fourhour-progress-v1.json'
progress=json.loads(progress_path.read_text())
assert not set(r['address'] for r in rows).intersection(progress['new_isolated_exact'])
progress['new_isolated_exact'] += [r['address'] for r in rows]
progress['accepted_exact']=new_exact
progress['new_instruction_bytes']+=sum(r['target_size'] for r in rows)
progress['pending_exact']=[]
assert len(progress['new_isolated_exact'])==new_exact-progress['baseline_exact']
progress_path.write_text(json.dumps(progress,indent=2)+'\n',encoding='utf-8')
for path in [area/'README.md',root/'WORKER_BRIEF.md',area/'worker-coordination/primary-status.md']:
 text=path.read_text(encoding='utf-8')
 replacements=[(f'{old_exact:,} equal-size',f'{new_exact:,} equal-size'),(f'{old_exact+4:,} C++',f'{new_exact+4:,} C++'),(f'{total-old_exact-4:,} fallback',f'{total-new_exact-4:,} fallback'),(f"{old['source_inputs_checked']:,} staged",f"{current['source_inputs_checked']:,} staged"),(f'verify_fm_primary_{old_phase}_checkpoint.py',f'verify_fm_primary_{phase}_checkpoint.py'),(old_path.name,current_path.name)]
 for before,after in replacements:
  text=text.replace(before,after)
 # The first bundle count is the current summary; later paragraphs retain historical counts.
 text=re.sub(r'all \d+ recovery bundles',f'all {int(sys.argv[3])} recovery bundles',text,count=1)
 text+=f"\n{phase.capitalize()} accepts {len(rows)} complete ranges ({', '.join(r['address'] for r in rows)}), totaling {sum(r['target_size'] for r in rows)} instruction bytes. Independent curated probes, full build, cumulative bundle checks, all active switch batches, finalization, warning audit and the current gate pass. The four-hour session has accepted {len(progress['new_isolated_exact'])} ranges and {progress['new_instruction_bytes']:,} instruction bytes.\n"
 path.write_text(text,encoding='utf-8')
claims=area/'worker-coordination/primary-claim.json'
data=json.loads(claims.read_text())
data['addresses']=[a for a in data['addresses'] if a not in {r['address'] for r in rows}]
data.update(baseline_gate=f'tools/kh2-audit/verify_fm_primary_{phase}_checkpoint.py',baseline_exact_matches=new_exact)
claims.write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
status=area/'worker-coordination/compiler-status.json'
data=json.loads(status.read_text())
data.update(state='idle',status='idle',phase=f'{phase}-accepted',last_accepted_phase=f'primary-{phase}',coordination='Acceptance complete. Coordinate compiler ownership before another shared build.')
status.write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
print(f'Published {phase}: {new_exact} accepted; session +{len(progress["new_isolated_exact"])} / {progress["new_instruction_bytes"]} bytes.')
