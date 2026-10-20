"""Identify complete 60-byte word-flag constructors from original opcodes."""
from pathlib import Path
import hashlib,json,sqlite3,struct,sys
base=Path(__file__).resolve().parent;workspace=base.parents[3];reference=workspace.parent/'Public/tools/kh2-reference'
sys.path.insert(0,str(reference/'tools'))
from common import load_elf_image,read_elf_vaddr,load_boundaries
image=load_elf_image(reference/'SLPM_666.75');assert hashlib.sha256(image[0]).hexdigest()=='d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
db=sqlite3.connect((workspace/'analysis/final-mix/worker-coordination/recovery-queue.sqlite3').as_uri()+'?mode=ro',uri=True)
states={a:(s,q,n) for a,s,q,n in db.execute('select address,state,queue,attempts from targets')}
accepted={r['address'] for r in json.loads((workspace/'analysis/final-mix/native-build/compiler-range-verification.json').read_text())}
fixed={0:0x27bdfff0,1:0xffb00000,2:0xffbf0008,4:0x0080802d,8:0xdfbf0008,9:0xae0f0000,12:0xdfb00000,13:0x03e00008,14:0x27bd0010}
rows=[]
for boundary in load_boundaries(reference/'layout.tsv'):
 if boundary.size!=60:continue
 code=read_elf_vaddr(image,boundary.addr,60);words=struct.unpack('<15I',code)
 if any(words[i]!=v for i,v in fixed.items()):continue
 if words[3]>>26!=3 or words[5]>>16!=0x3c0f or words[6]>>16!=0x8e0e or words[7]>>16!=0x25ef or words[10]>>16!=0x35ce or words[11]>>16!=0xae0e or (words[6]&65535)!=(words[11]&65535):continue
 low=(words[7]&65535)-(65536 if words[7]&32768 else 0);address=f'{boundary.addr:08x}'
 rows.append({'address':address,'bytes':60,'vtable':f'{((words[5]&65535)<<16)+low:08x}','helper':f'{(words[3]&0x3ffffff)<<2:08x}','field_offset':words[6]&65535,'mask':words[10]&65535,'accepted':address in accepted,'state':states.get(address),'target_sha256':hashlib.sha256(code).hexdigest()})
pending=[r for r in rows if not r['accepted'] and r['state'] and r['state'][:2]==('ready','general')]
helpers={r['helper'] for r in pending}
exports={}
for line in (workspace/'analysis/final-mix/native-pseudocode/main.jsonl').open():
 row=json.loads(line)
 if row['address'] in helpers:exports[row['address']]=row['code']
output={'all':rows,'pending':pending,'helper_exports':exports};path=base/'flag-constructor-census.json';assert not path.exists();path.write_text(json.dumps(output,indent=2)+'\n')
print(f'Complete family: {len(rows)}; ready general: {len(pending)}')
print(json.dumps(pending,indent=2));print(json.dumps(exports,indent=2))
