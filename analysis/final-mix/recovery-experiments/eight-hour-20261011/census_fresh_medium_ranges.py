"""Read-only orientation of ready medium ranges; original boundaries remain authoritative."""
from pathlib import Path
import json,sqlite3,struct,sys,collections
base=Path(__file__).resolve().parent;workspace=base.parents[3];reference=workspace.parent/'Public/tools/kh2-reference'
sys.path.insert(0,str(reference/'tools'))
from common import load_elf_image,read_elf_vaddr,load_boundaries
image=load_elf_image(reference/'SLPM_666.75')
db=sqlite3.connect((workspace/'analysis/final-mix/worker-coordination/recovery-queue.sqlite3').as_uri()+'?mode=ro',uri=True)
states={a:(s,q,n) for a,s,q,n in db.execute('select address,state,queue,attempts from targets')}
accepted={r['address'] for r in json.loads((workspace/'analysis/final-mix/native-build/compiler-range-verification.json').read_text())}
rows=[]
for boundary in load_boundaries(reference/'layout.tsv'):
 address=f'{boundary.addr:08x}';state=states.get(address)
 if address in accepted or not state or state[:2]!=('ready','general') or not 56<=boundary.size<=160:continue
 words=struct.unpack('<'+str(boundary.size//4)+'I',read_elf_vaddr(image,boundary.addr,boundary.size))
 calls=[f'{(w&0x3ffffff)<<2:08x}' for w in words if w>>26 in (2,3)]
 rows.append({'address':address,'bytes':boundary.size,'attempts':state[2],'calls':calls,'branch_count':sum(w>>26 in (1,4,5,6,7,20,21,22,23) for w in words)})
code={}
selected=sorted(rows,key=lambda r:(r['attempts'],r['branch_count'],r['bytes'],r['address']))[:40]
needed={r['address'] for r in selected}
for line in (workspace/'analysis/final-mix/native-pseudocode/main.jsonl').open():
 row=json.loads(line);address=row['address']
 if address in needed:code[address]=row['code']
output={'counts_by_size':dict(collections.Counter(r['bytes'] for r in rows)),'selected':[dict(r,code=code.get(r['address'])) for r in selected]}
path=base/'fresh-medium-range-census.json';assert not path.exists();path.write_text(json.dumps(output,indent=2)+'\n')
print(json.dumps(output,indent=2))
