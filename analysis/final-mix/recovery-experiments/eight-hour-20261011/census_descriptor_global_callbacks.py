"""Recognize complete descriptor-store/global-callback wrappers from original words."""
from pathlib import Path
import hashlib,json,sqlite3,struct,sys
base=Path(__file__).resolve().parent;workspace=base.parents[3];reference=workspace.parent/'Public/tools/kh2-reference'
sys.path.insert(0,str(reference/'tools'))
from common import load_elf_image,read_elf_vaddr,load_boundaries
image=load_elf_image(reference/'SLPM_666.75');db=sqlite3.connect((workspace/'analysis/final-mix/worker-coordination/recovery-queue.sqlite3').as_uri()+'?mode=ro',uri=True)
states={a:(s,q,n) for a,s,q,n in db.execute('select address,state,queue,attempts from targets')}
accepted={r['address'] for r in json.loads((workspace/'analysis/final-mix/native-build/compiler-range-verification.json').read_text())};rows=[]
def absolute(hi,lo):return ((hi&65535)<<16)+(lo&65535)-(65536 if lo&32768 else 0)
for boundary in load_boundaries(reference/'layout.tsv'):
 if boundary.size not in (60,64):continue
 code=read_elf_vaddr(image,boundary.addr,boundary.size);w=struct.unpack('<'+str(boundary.size//4)+'I',code)
 fixed={1:0x27bdfff0,3:0xffbf0000,4:0xac8f0000,5:0x0080282d}
 if any(w[i]!=v for i,v in fixed.items()) or w[0]>>16!=0x3c0f or w[2]>>16!=0x25ef or w[6]>>16!=0x3c0f:continue
 nested=boundary.size==64
 if nested:
  extra={9:0x8c8d0000,11:0x01e0f809,12:0,13:0xdfbf0000,14:0x03e00008,15:0x27bd0010}
  if any(w[i]!=v for i,v in extra.items()) or w[7]>>16!=0x8dee or w[8]>>16!=0x8dc4 or w[10]>>16!=0x8daf:continue
  field=w[8]&65535;slot=w[10]&65535
 else:
  extra={8:0x8c8e0000,10:0x01e0f809,11:0,12:0xdfbf0000,13:0x03e00008,14:0x27bd0010}
  if any(w[i]!=v for i,v in extra.items()) or w[7]>>16!=0x8de4 or w[9]>>16!=0x8dcf:continue
  field=None;slot=w[9]&65535
 if slot%4 or field is not None and field%4:continue
 address=f'{boundary.addr:08x}';rows.append({'address':address,'bytes':boundary.size,'descriptor':f'{absolute(w[0],w[2]):08x}','global':f'{absolute(w[6],w[7]):08x}','receiver_field':field,'callback_slot':slot,'accepted':address in accepted,'state':states.get(address),'target_sha256':hashlib.sha256(code).hexdigest()})
pending=[r for r in rows if not r['accepted'] and r['state'] and r['state'][:2]==('ready','general')]
output={'all':rows,'pending':pending};path=base/'descriptor-global-callback-census.json';assert not path.exists();path.write_text(json.dumps(output,indent=2)+'\n')
print(f'Complete wrappers: {len(rows)}; pending general-ready: {len(pending)}');print(json.dumps(pending,indent=2))
