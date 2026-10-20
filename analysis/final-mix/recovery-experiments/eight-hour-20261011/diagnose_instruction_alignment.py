from pathlib import Path
import struct,subprocess,json,hashlib,sys
stage=Path('/root/kh2fm-build');out=stage/'out/alignment-diagnostic';base=Path(__file__).resolve().parent;sys.path.insert(0,str(stage/'tools'))
from build_elf import parse_elf_function_symbols
from common import load_elf_image,read_elf_vaddr
obj=stage/'out/build/src/anon/fm_primary_queuekappaprime_recovered_002b6b84.o';raw=obj.read_bytes();data=bytearray(raw);off=struct.unpack_from('<I',data,0x20)[0];ent,num,index=struct.unpack_from('<HHH',data,0x2e);headers=[struct.unpack_from('<10I',data,off+i*ent) for i in range(num)];s=headers[index];strings=data[s[4]:s[4]+s[5]];changes=[]
for i,sh in enumerate(headers):
 name=strings[sh[0]:].split(b'\0',1)[0].decode()
 if name=='.text._Z13func_002b6b84Pv':
  assert sh[8]==8;struct.pack_into('<I',data,off+i*ent+32,4);changes.append({'section':name,'old_alignment':sh[8],'new_alignment':4,'header_offset':off+i*ent+32})
assert len(changes)==1
patched=out/'instruction-aligned-callee.o';assert not patched.exists();patched.write_bytes(data)
rsp=out/'instruction-aligned-link.rsp';assert not rsp.exists();rsptext=(stage/'out/link.rsp').read_text();needle=str(obj.relative_to(stage));assert rsptext.count(needle)==1;rsp.write_text(rsptext.replace(needle,str(patched.relative_to(stage))))
elf=out/'instruction-aligned-full.elf'
cmd=['docker','run','--rm','--platform','linux/amd64','-v',f'{stage}:/work','-w','/work','kh2-local/ps2-compiler:3.2-ee-040921-objdiff','/opt/ps2/gcc/bin/ee-ld','--no-check-sections','-T','out/generated/kh2.temp.ld','-T',str(rsp.relative_to(stage)),'-o',str(elf.relative_to(stage)),'-L/opt/ps2/gcc/lib/gcc-lib/ee/3.2-ee-040921','-lgcc']
subprocess.run(cmd,check=True)
original=load_elf_image(stage/'SLPM_666.75');rows=[]
for variant,path in [('baseline',stage/'out/linked.tmp.elf'),('instruction-aligned',elf)]:
 binary=path.read_bytes()
 for symbol in parse_elf_function_symbols(path,None):
  if '002b6b84' not in symbol.name and '002b9ab8' not in symbol.name:continue
  target=0x2b6b84 if '002b6b84' in symbol.name else 0x2b9ab8
  native=read_elf_vaddr(original,target,symbol.size);compiled=binary[symbol.foff:symbol.foff+symbol.size]
  rows.append({'variant':variant,'symbol':symbol.name,'expected_address':hex(target),'linked_address':hex(symbol.addr),'size':symbol.size,'exact_bytes':native==compiled,'native_hex':native.hex(),'compiled_hex':compiled.hex()})
receipt={'object_original_sha256':hashlib.sha256(raw).hexdigest(),'object_patched_sha256':hashlib.sha256(data).hexdigest(),'metadata_changes':changes,'rows':rows}
p=base/'queuekappaprime-instruction-alignment-diagnostic.json';assert not p.exists();p.write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(receipt,indent=2))
assert all(row['exact_bytes'] and row['expected_address']==row['linked_address'] for row in rows if row['variant']=='instruction-aligned')
