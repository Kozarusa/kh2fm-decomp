"""Find complete SDK gateway wrappers matching the two proven frame controls."""
from pathlib import Path
import hashlib,json,sqlite3,struct,sys
base=Path(__file__).resolve().parent;workspace=base.parents[3];reference=workspace.parent/'Public/tools/kh2-reference'
sys.path.insert(0,str(reference/'tools'))
from common import load_elf_image,read_elf_vaddr,load_boundaries
image=load_elf_image(reference/'SLPM_666.75');db=sqlite3.connect((workspace/'analysis/final-mix/worker-coordination/recovery-queue.sqlite3').as_uri()+'?mode=ro',uri=True)
states={a:(s,q,n) for a,s,q,n in db.execute('select address,state,queue,attempts from targets')}
accepted={r['address'] for r in json.loads((workspace/'analysis/final-mix/native-build/compiler-range-verification.json').read_text())};rows=[]
for boundary in load_boundaries(reference/'layout.tsv'):
 if boundary.size==56:
  fixed={0:0x27bdfff0,1:0xffbe0000,2:0xffbf0008,3:0x03a0f02d,5:0x0c0ad9c2,7:0x0040782d,8:0x01e0102d,9:0x03c0e82d,10:0xdfbe0000,11:0xdfbf0008,12:0x03e00008,13:0x27bd0010};count_index=4;operation_index=6;payloads=0
 elif boundary.size==64:
  fixed={0:0x27bdffe0,1:0xffbe0010,2:0xffbf0018,3:0x03a0f02d,4:0xafc40000,7:0x0c0ad9c2,8:0x8fc60000,9:0x0040782d,10:0x01e0102d,11:0x03c0e82d,12:0xdfbe0010,13:0xdfbf0018,14:0x03e00008,15:0x27bd0020};count_index=5;operation_index=6;payloads=1
 else:continue
 code=read_elf_vaddr(image,boundary.addr,boundary.size);w=struct.unpack('<'+str(boundary.size//4)+'I',code)
 if any(w[i]!=v for i,v in fixed.items()) or w[count_index]>>16!=0x2404 or w[operation_index]>>16!=0x2405:continue
 count=w[count_index]&65535;operation=w[operation_index]&65535
 if count!=payloads+1 or operation>=32768:continue
 address=f'{boundary.addr:08x}';rows.append({'address':address,'bytes':boundary.size,'count':count,'operation':operation,'payloads':payloads,'accepted':address in accepted,'state':states.get(address),'target_sha256':hashlib.sha256(code).hexdigest()})
assert any(r['address']=='002b7f84' for r in rows) and any(r['address']=='002b6b84' for r in rows)
pending=[r for r in rows if not r['accepted'] and r['state'] and r['state'][:2]==('ready','general')]
path=base/'sdk-frame-wrapper-census.json';assert not path.exists();path.write_text(json.dumps({'positive_controls':['002b7f84','002b6b84'],'all':rows,'pending':pending},indent=2)+'\n')
print(f'Complete gateway wrappers: {len(rows)}; unaccepted ready candidates: {len(pending)}');print(json.dumps(pending,indent=2))
