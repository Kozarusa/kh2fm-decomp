"""Read-only census of table assignment, global clear, and two typed object calls."""
from pathlib import Path
import hashlib
import json
import sqlite3
import struct
import sys
base = Path(__file__).resolve().parent
workspace = base.parents[3]
reference = workspace.parent / 'Public/tools/kh2-reference'
sys.path.insert(0,str(reference/'tools'))
from common import load_elf_image,read_elf_vaddr,load_boundaries
image = load_elf_image(reference/'SLPM_666.75')
assert hashlib.sha256(image[0]).hexdigest()=='d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
accepted = {row['address'] for row in json.loads((workspace/'analysis/final-mix/native-build/compiler-range-verification.json').read_text())}
db = sqlite3.connect((workspace/'analysis/final-mix/worker-coordination/recovery-queue.sqlite3').as_uri()+'?mode=ro',uri=True)
states = {a:(state,queue) for a,state,queue in db.execute('select address,state,queue from targets')}
fixed = {1:0x27bdfff0,3:0xffb00000,4:0xac8f0000,6:0xffbf0008,7:0x0080802d,10:0x0200202d,11:0xdfbf0008,12:0xdfb00000,14:0x27bd0010}
rows = []
def address(high,low):
    immediate = (low&0xffff)-(0x10000 if low&0x8000 else 0)
    return f'{((high&0xffff)<<16)+immediate:08x}'
for boundary in load_boundaries(reference/'layout.tsv'):
    if boundary.size!=60:
        continue
    code = read_elf_vaddr(image,boundary.addr,60)
    words = struct.unpack('<15I',code)
    if any(words[index]!=value for index,value in fixed.items()):
        continue
    if words[0]>>16!=0x3c0f or words[2]>>16!=0x25ef or words[5]>>16!=0x3c0e or words[9]>>16!=0xadc0 or words[8]>>26!=3 or words[13]>>26!=2:
        continue
    key = f'{boundary.addr:08x}'
    rows.append({'address':key,'vtable':address(words[0],words[2]),'cleared_global':address(words[5],words[9]),'first_helper':f'{(words[8]&0x3ffffff)<<2:08x}','final_helper':f'{(words[13]&0x3ffffff)<<2:08x}','accepted':key in accepted,'state':states.get(key),'target_sha256':hashlib.sha256(code).hexdigest()})
with (base/'global-clearing-wrapper-census.json').open('x') as stream:
    json.dump(rows,stream,indent=2)
pending = [row for row in rows if not row['accepted'] and row['state']==('ready','general')]
print(f'Complete family: {len(rows)}; pending general-ready: {len(pending)}')
print(json.dumps(pending,indent=2))
