"""Preserve the failed full ELF and locate byte differences by original ranges."""
from pathlib import Path
import hashlib,json,sys
base=Path(__file__).resolve().parent;stage=Path('/root/kh2fm-build')
sys.path.insert(0,str(stage/'tools'))
from common import load_elf_image,read_elf_vaddr,load_boundaries
original=load_elf_image(stage/'SLPM_666.75');compiled=load_elf_image(stage/'kh2.elf')
saved=base/'queuekappaprime-failed-full.elf';assert not saved.exists();saved.write_bytes((stage/'kh2.elf').read_bytes())
rows=[]
for boundary in load_boundaries(stage/'layout.tsv'):
 a=read_elf_vaddr(original,boundary.addr,boundary.size);b=read_elf_vaddr(compiled,boundary.addr,boundary.size)
 if a!=b:
  rows.append({'address':f'{boundary.addr:08x}','bytes':boundary.size,'differences':[{'address':f'{boundary.addr+i:08x}','original':a[i],'compiled':b[i]} for i in range(len(a)) if a[i]!=b[i]],'target_hex':a.hex(),'compiled_hex':b.hex()})
receipt={'failed_elf_sha256':hashlib.sha256(saved.read_bytes()).hexdigest(),'rows':rows}
path=base/'queuekappaprime-link-failure.json';assert not path.exists();path.write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(receipt,indent=2))

