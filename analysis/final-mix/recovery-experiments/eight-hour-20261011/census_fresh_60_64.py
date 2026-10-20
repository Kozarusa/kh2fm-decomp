from pathlib import Path
import json,sqlite3,struct,sys
base=Path(__file__).resolve().parent;workspace=base.parents[3];reference=workspace.parent/'Public/tools/kh2-reference'
sys.path.insert(0,str(reference/'tools'))
from common import load_elf_image,read_elf_vaddr,load_boundaries
image=load_elf_image(reference/'SLPM_666.75');db=sqlite3.connect((workspace/'analysis/final-mix/worker-coordination/recovery-queue.sqlite3').as_uri()+'?mode=ro',uri=True)
states={a:(s,q,n) for a,s,q,n in db.execute('select address,state,queue,attempts from targets')};rows=[]
for boundary in load_boundaries(reference/'layout.tsv'):
 address=f'{boundary.addr:08x}';state=states.get(address)
 if boundary.size not in (60,64) or state!=('ready','general',0):continue
 words=struct.unpack('<'+str(boundary.size//4)+'I',read_elf_vaddr(image,boundary.addr,boundary.size))
 branches=sum(w>>26 in (1,4,5,6,7,20,21,22,23) for w in words)
 if branches:continue
 rows.append({'address':address,'bytes':boundary.size,'calls':[f'{(w&0x3ffffff)<<2:08x}' for w in words if w>>26 in (2,3)],'words':[f'{w:08x}' for w in words]})
needed={r['address'] for r in rows};exports={}
for line in (workspace/'analysis/final-mix/native-pseudocode/main.jsonl').open():
 row=json.loads(line)
 if row['address'] in needed:exports[row['address']]=row['code']
for row in rows:row['code']=exports.get(row['address'])
path=base/'fresh-60-64-census.json';assert not path.exists();path.write_text(json.dumps(rows,indent=2)+'\n')
print(f'Fresh straight-line ranges: {len(rows)}')
print(json.dumps([{k:v for k,v in row.items() if k!='words'} for row in rows[:32]],indent=2))
