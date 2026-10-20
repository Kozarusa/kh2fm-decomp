from pathlib import Path
import hashlib,json,struct
from datetime import datetime,timezone

area=Path(__file__).resolve().parent.parent
root=area.parents[1]
original=(root.parent/'Public/tools/kh2-reference/SLPM_666.75').read_bytes()
assert hashlib.sha256(original).hexdigest()=='d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
phoff=struct.unpack_from('<I',original,28)[0]
phsize,phcount=struct.unpack_from('<HH',original,42)
loads=[]
for i in range(phcount):
 kind,offset,vaddr,_,filesize,_,_,_=struct.unpack_from('<8I',original,phoff+i*phsize)
 if kind==1: loads.append((vaddr,offset,filesize))
assignments={
 'lookup-search':['00114438','00114490','00124c48'],
 'global-copy':['00158ac8','00158b20'],
 'float-predicates':['0010f6f8','00148638'],
 'global-initializers':['0014ec40','00158fd8','00159c58'],
 'framed-epilogues':['0014dc48','0014dca8','002e5f70'],
 'framed-transport':['00143470','0013e610'],
}
flat=[a for addresses in assignments.values() for a in addresses]
assert len(flat)==len(set(flat))
result={'created_utc':datetime.now(timezone.utc).isoformat(),'disjoint_targets':len(flat),'assignments':[]}
for name,addresses in assignments.items():
 directory=area/'recovery-experiments/delegated'/name
 proofs=[]
 for path in sorted(directory.glob('*.verification.json')):
  proof=json.loads(path.read_text())
  source=root/proof['source']
  assert source.is_file(),source
  assert hashlib.sha256(source.read_bytes()).hexdigest()==proof['source_sha256'],source
  for row in proof['rows']:
   assert row['address'] in addresses,(name,row['address'])
   compiled=bytes.fromhex(row['compiled_hex'])
   target=bytes.fromhex(row['target_hex'])
   address=int(row['address'],16)
   mapping=[(base,offset,size) for base,offset,size in loads if base<=address and address+len(target)<=base+size]
   assert len(mapping)==1
   base,offset,_=mapping[0]
   assert original[offset+address-base:offset+address-base+len(target)]==target
   assert len(compiled)==row['compiled_size'] and len(target)==row['target_size']
   assert row['exact_match']==(compiled==target)
   proofs.append({'address':row['address'],'exact':row['exact_match'],'compiled_size':len(compiled),'target_size':len(target),'source':str(source),'source_sha256':proof['source_sha256'],'proof':str(path),'proof_sha256':hashlib.sha256(path.read_bytes()).hexdigest()})
 report=directory/'REPORT.md'
 result['assignments'].append({'name':name,'addresses':addresses,'report_exists':report.is_file(),'report_sha256':hashlib.sha256(report.read_bytes()).hexdigest() if report.is_file() else None,'proofs':proofs})
 print(name, 'proofs',len(proofs),'exact',sum(p['exact'] for p in proofs),'report',report.is_file())
destination=area/'worker-coordination/delegated-proof-audit.json'
destination.write_text(json.dumps(result,indent=2),encoding='utf-8')
