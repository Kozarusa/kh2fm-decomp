"""Independent assembly review only; never changes registration or C++ counts."""
import hashlib,json,shutil,subprocess,sys
from pathlib import Path
w=Path('/mnt/c/Users/KoZa/Documents/AGENTS')
stage=Path('/root/kh2fm-build')
sys.path.insert(0,str(stage/'tools'))
from build_elf import parse_elf_function_symbols
from common import load_elf_image,read_elf_vaddr,load_boundaries
area=w/'Codex/analysis/final-mix'
base=area/'recovery-experiments/queue-run-20261009/recovery-b'
out=area/'recovery-experiments/queue-run-20261009/primary'
receipt=json.loads((base/'startup-assembly-receipt.json').read_text())
digest=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
original=load_elf_image(stage/'SLPM_666.75')
assert hashlib.sha256(original[0]).hexdigest()=='d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
boundaries={r.addr:r for r in load_boundaries(stage/'layout.tsv')}
image='kh2-local/ps2-compiler:3.2-ee-040921-objdiff'
results=[]
for item in receipt['artifacts']:
 address=item['address']; addr=int(address,16); size=item['bytes']
 source=base/item['source']; proof=base/item['proof']
 assert digest(source)==item['source_sha256'] and digest(proof)==item['proof_sha256']
 assert boundaries[addr].size==size
 text=source.read_text()
 assert all(directive not in text for directive in ['.word','.byte','.incbin','.space','.fill'])
 saved=json.loads(proof.read_text()); row=saved['rows'][0]
 target=read_elf_vaddr(original,addr,size)
 assert len(saved['rows'])==1 and row['address']==address
 assert row['compiled_size']==row['target_size']==size
 assert bytes.fromhex(row['target_hex'])==bytes.fromhex(row['compiled_hex'])==target
 scratch=stage/'recovery-experiments'/('primary_startup_review_'+address)
 scratch.mkdir(exist_ok=False)
 shutil.copyfile(source,scratch/'source.S')
 section='.text._Z13func_'+address+'v'
 (scratch/'source.ld').write_text('func_0030f468 = 0x0030f468;\nSECTIONS { .review 0x'+address+' : { *('+section+') } }\n')
 rel=scratch.relative_to(stage).as_posix()
 with (out/('startup-'+address+'-independent.log')).open('x') as log:
  for tool,args in [('ee-as',[rel+'/source.S','-o',rel+'/source.o']),('ee-ld',['--no-check-sections','-T',rel+'/source.ld',rel+'/source.o','-o',rel+'/source.elf'])]:
   subprocess.run(['docker','run','--rm','--platform','linux/amd64','-v',str(stage)+':/work','-w','/work',image,'/opt/ps2/gcc/bin/'+tool,*args],stdout=log,stderr=subprocess.STDOUT,check=True)
 symbols=[s for s in parse_elf_function_symbols(scratch/'source.elf',section_name=None) if s.name=='_Z13func_'+address+'v']
 assert len(symbols)==1 and symbols[0].size==size and symbols[0].addr==addr
 sym=symbols[0]; linked=(scratch/'source.elf').read_bytes(); compiled=linked[sym.foff:sym.foff+size]
 assert compiled==target
 results.append(dict(address=address,size=size,source_sha256=digest(source),worker_proof_sha256=digest(proof),original_range_sha256=hashlib.sha256(target).hexdigest(),linked_elf_sha256=hashlib.sha256(linked).hexdigest(),compiled_hex=compiled.hex(),target_hex=target.hex(),exact_match=True,abi=item['abi']))
 print(address,size,'independent structured assembly exact; not integrated',flush=True)
report=dict(kind='independent_structured_assembly_review_not_cpp_acceptance',compiler_image=image,original_elf_sha256=hashlib.sha256(original[0]).hexdigest(),receipt_sha256=digest(base/'startup-assembly-receipt.json'),integrated=False,cpp_count_delta=0,rows=results)
(out/'startup-assembly-independent-review.json').write_text(json.dumps(report,indent=2)+'\n')
