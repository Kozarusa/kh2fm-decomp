"""Enumerate small first-helper constructors without assuming a fixed restore position."""
from pathlib import Path
import hashlib,json,sqlite3,struct,sys
base=Path(__file__).resolve().parent;workspace=base.parents[3];reference=workspace.parent/'Public/tools/kh2-reference'
sys.path.insert(0,str(reference/'tools'))
from common import load_elf_image,read_elf_vaddr,load_boundaries
image=load_elf_image(reference/'SLPM_666.75');db=sqlite3.connect((workspace/'analysis/final-mix/worker-coordination/recovery-queue.sqlite3').as_uri()+'?mode=ro',uri=True)
states={a:(s,q,n) for a,s,q,n in db.execute('select address,state,queue,attempts from targets')}
accepted={r['address'] for r in json.loads((workspace/'analysis/final-mix/native-build/compiler-range-verification.json').read_text())};rows=[]
for boundary in load_boundaries(reference/'layout.tsv'):
 if not 56<=boundary.size<=92:continue
 address=f'{boundary.addr:08x}';state=states.get(address)
 if address in accepted or not state or state[:2]!=('ready','general'):continue
 code=read_elf_vaddr(image,boundary.addr,boundary.size);words=struct.unpack('<'+str(boundary.size//4)+'I',code)
 if words[0]!=0x27bdfff0 or words[1]!=0xffb00000 or words[2]!=0xffbf0008 or words[3]>>26!=3 or words[4]!=0x0080802d:continue
 if words[-3:]!=(0xdfb00000,0x03e00008,0x27bd0010) or sum(w>>26 in (2,3) for w in words)!=1:continue
 if 0xae0f0000 not in words:continue
 hi=[w&65535 for w in words[5:] if w>>16==0x3c0f];lo=[(w&65535)-(65536 if w&32768 else 0) for w in words[5:] if w>>16==0x25ef]
 if len(hi)!=1 or len(lo)!=1:continue
 rows.append({'address':address,'bytes':boundary.size,'attempts':state[2],'helper':f'{(words[3]&0x3ffffff)<<2:08x}','vtable':f'{(hi[0]<<16)+lo[0]:08x}','words':[f'{w:08x}' for w in words],'target_sha256':hashlib.sha256(code).hexdigest()})
helpers={r['helper'] for r in rows};exports={}
for line in (workspace/'analysis/final-mix/native-pseudocode/main.jsonl').open():
 row=json.loads(line)
 if row['address'] in helpers|{r['address'] for r in rows}:exports[row['address']]=row['code']
path=base/'flag-constructor-census-v2.json';assert not path.exists();path.write_text(json.dumps({'rows':rows,'exports':exports},indent=2)+'\n')
print(f'Unaccepted ready constructors: {len(rows)}');print(json.dumps(rows,indent=2));print(json.dumps(exports,indent=2))
