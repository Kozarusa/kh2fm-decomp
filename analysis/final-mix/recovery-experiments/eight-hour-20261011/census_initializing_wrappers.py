"""Find complete first-helper/table-update/final-helper 52-byte ranges."""
from pathlib import Path
import hashlib
import json
import sqlite3
import struct
import sys
base=Path(__file__).resolve().parent
workspace=base.parents[3]
reference=workspace.parent/'Public/tools/kh2-reference'
sys.path.insert(0,str(reference/'tools'))
from common import load_elf_image,read_elf_vaddr,load_boundaries
image=load_elf_image(reference/'SLPM_666.75')
assert hashlib.sha256(image[0]).hexdigest()=='d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
accepted={row['address'] for row in json.loads((workspace/'analysis/final-mix/native-build/compiler-range-verification.json').read_text())}
db=sqlite3.connect((workspace/'analysis/final-mix/worker-coordination/recovery-queue.sqlite3').as_uri()+'?mode=ro',uri=True)
states={a:(state,queue) for a,state,queue in db.execute('select address,state,queue from targets')}
fixed={0:0x27bdfff0,1:0xffb00000,2:0xffbf0008,4:0x0080802d,6:0xdfbf0008,8:0x0200202d,9:0xae0f0000,10:0xdfb00000,12:0x27bd0010}
rows=[]
for boundary in load_boundaries(reference/'layout.tsv'):
    if boundary.size!=52:
        continue
    code=read_elf_vaddr(image,boundary.addr,52)
    words=struct.unpack('<13I',code)
    if any(words[index]!=value for index,value in fixed.items()):
        continue
    if words[3]>>26!=3 or words[5]>>16!=0x3c0f or words[7]>>16!=0x25ef or words[11]>>26!=2:
        continue
    address=f'{boundary.addr:08x}'
    low=(words[7]&0xffff)-(0x10000 if words[7]&0x8000 else 0)
    rows.append({'address':address,'vtable':f'{((words[5]&0xffff)<<16)+low:08x}','first_helper':f'{(words[3]&0x3ffffff)<<2:08x}','final_helper':f'{(words[11]&0x3ffffff)<<2:08x}','accepted':address in accepted,'state':states.get(address),'target_sha256':hashlib.sha256(code).hexdigest()})
with (base/'initializing-wrapper-census.json').open('x') as stream:
    json.dump(rows,stream,indent=2)
pending=[row for row in rows if not row['accepted'] and row['state']==('ready','general')]
print(f'Complete family: {len(rows)}; pending general-ready: {len(pending)}')
print(json.dumps(pending,indent=2))
