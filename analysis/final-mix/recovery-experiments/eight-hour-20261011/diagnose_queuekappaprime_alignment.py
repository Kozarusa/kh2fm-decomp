from pathlib import Path
import hashlib,json,subprocess,sys,re
base=Path(__file__).resolve().parent;stage=Path('/root/kh2fm-build');sys.path.insert(0,str(stage/'tools'))
from build_elf import parse_elf_function_symbols
from common import load_elf_image,read_elf_vaddr
out=stage/'out/alignment-diagnostic';out.mkdir(exist_ok=True)
sections=(stage/'out/generated/cxx_sections.ld').read_text()
fixed=re.sub(r'(\.kh2cxx_([0-9a-f]{8}) 0x[0-9a-f]{8} :)',lambda m:m[1]+(' SUBALIGN(4)' if int(m[2],16)%8==4 else ''),sections)
script=(stage/'kh2.ld').read_text().replace('/* @CXX_SECTIONS@ */',fixed)
ld=out/'subalign.ld';assert not ld.exists();ld.write_text(script)
cmd=['docker','run','--rm','--platform','linux/amd64','-v',f'{stage}:/work','-w','/work','kh2-local/ps2-compiler:3.2-ee-040921-objdiff','/opt/ps2/gcc/bin/ee-ld','--no-check-sections','-T','out/alignment-diagnostic/subalign.ld','-T','out/link.rsp','-o','out/alignment-diagnostic/subalign.elf','-L/opt/ps2/gcc/lib/gcc-lib/ee/3.2-ee-040921','-lgcc']
subprocess.run(cmd,check=True)
original=load_elf_image(stage/'SLPM_666.75');rows=[]
for variant,path in [('baseline',stage/'out/linked.tmp.elf'),('subalign',out/'subalign.elf')]:
 data=path.read_bytes()
 for symbol in parse_elf_function_symbols(path,None):
  if '002b6b84' not in symbol.name and '002b9ab8' not in symbol.name:continue
  target=0x2b6b84 if '002b6b84' in symbol.name else 0x2b9ab8
  native=read_elf_vaddr(original,target,symbol.size);compiled=data[symbol.foff:symbol.foff+symbol.size]
  rows.append({'variant':variant,'symbol':symbol.name,'expected_address':hex(target),'linked_address':hex(symbol.addr),'size':symbol.size,'exact_bytes':native==compiled,'native_hex':native.hex(),'compiled_hex':compiled.hex()})
receipt=base/'queuekappaprime-alignment-diagnostic.json';assert not receipt.exists();receipt.write_text(json.dumps({'rows':rows,'script_sha256':hashlib.sha256(ld.read_bytes()).hexdigest()},indent=2)+'\n');print(json.dumps(rows,indent=2))
assert all(row['exact_bytes'] and row['expected_address']==row['linked_address'] for row in rows if row['variant']=='subalign')
