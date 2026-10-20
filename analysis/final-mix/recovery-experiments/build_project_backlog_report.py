from pathlib import Path
import json,csv,hashlib
root=Path(__file__).resolve().parents[3]
public=root.parent/'Public'
area=root/'analysis/final-mix'
ex=area/'recovery-experiments'
accepted={r['address'] for r in json.loads((area/'native-build/compiler-range-verification.json').read_text())}
main={r['address']:r for r in (json.loads(line) for line in (area/'native-pseudocode/main.jsonl').read_text().splitlines())}
layout=list(csv.DictReader((l for l in (public/'tools/kh2-reference/layout.tsv').read_text().splitlines() if not l.startswith('#')),delimiter='\t'))
best={}
for f in ex.glob('*.verification.json'):
 try:
  proof=json.loads(f.read_text()); src=f.with_suffix('').with_suffix('.cpp')
  if not src.exists() or hashlib.sha256(src.read_bytes()).hexdigest()!=proof.get('source_sha256'): continue
  for row in proof.get('rows',[]):
   a=row['address']
   if a in accepted: continue
   left=bytes.fromhex(row['compiled_hex']); right=bytes.fromhex(row['target_hex'])
   mismatches=sum(left[i:i+4]!=right[i:i+4] for i in range(0,max(len(left),len(right)),4))
   score=(abs(len(left)-len(right)),mismatches)
   if a not in best or score<best[a][0]: best[a]=(score,{'proof':f.relative_to(root).as_posix(),'source':src.relative_to(root).as_posix(),'compiled_bytes':len(left),'target_bytes':len(right),'different_words':mismatches})
 except (ValueError,KeyError): continue
remaining=[]
for row in layout:
 a=row['addr']
 if a in accepted: continue
 size=int(row['size'],0) if row['size'].startswith('0x') else int(row['size'])
 evidence=best.get(a)
 priority=1 if evidence and evidence[0][0]==0 and evidence[0][1]<=3 else 2 if size<=128 else 3 if size<=512 else 4
 remaining.append({'address':a,'end':row['end'],'bytes':size,'priority':priority,'pseudocode_available':a in main,'callees':main.get(a,{}).get('callees',[]),'best_proposal':evidence[1] if evidence else None})
remaining.sort(key=lambda r:(r['priority'],r['best_proposal']['different_words'] if r['best_proposal'] else 999,r['bytes'],r['address']))
out={'accepted_cpp_ranges':len(accepted),'remaining_ranges':len(remaining),'priority_policy':'1: equal-size proposals differing in at most three words; 2: remaining ranges up to 128 bytes; 3: 129-512 bytes; 4: larger ranges. Size is a scheduling proxy, not a correctness or effort guarantee. Additional undiscovered boundaries and data recovery are separate work.','ordered_ranges':remaining}
(area/'project-prioritized-range-backlog.json').write_text(json.dumps(out,indent=2)+'\n',encoding='utf-8')
print('Backlog inventory:',len(remaining),'ranges; priority counts:',{p:sum(r['priority']==p for r in remaining) for p in range(1,5)})
