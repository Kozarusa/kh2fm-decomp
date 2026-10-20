from pathlib import Path
import subprocess,sys,json,hashlib,shutil
stage=Path('/root/kh2fm-build')
sys.path.insert(0,str(stage/'tools'))
from build_elf import parse_elf_function_symbols
base=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-b')
image='kh2-local/ps2-compiler:3.2-ee-040921-objdiff'
original=(stage/'SLPM_666.75').read_bytes()
assert hashlib.sha256(original).hexdigest()=='d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
for address,token,source_name,abi in [('00100228','70118fc3','recovery_b_00100228_70118fc3_startup_v2.S','Incoming v0 cursor and v1 exclusive end; outgoing v0=end; a0 scratch; no frame.'),('001002a0','c03ab829','recovery_b_001002a0_c03ab829_startup_thunk.S','Tail jump to0030f468, preserving incoming registers and original link register.')]:
 source=base/source_name
 scratch=stage/'recovery-experiments'/('recovery_b_'+address+'_'+token+'_directasm')
 scratch.mkdir(exist_ok=True)
 shutil.copyfile(source,scratch/'source.S')
 rel=scratch.relative_to(stage).as_posix()
 linker=f'func_0030f468 = 0x0030f468;\nSECTIONS {{ .s_{address} 0x{address} : {{ *(.text._Z13func_{address}v) }} }}\n'
 (scratch/'source.ld').write_text(linker)
 def run(command):
  subprocess.run(['docker','run','--rm','--platform','linux/amd64','-v',str(stage)+':/work','-w','/work',image,'bash','-lc',command],check=True)
 with source.with_suffix('.direct-assembly.log').open('w') as log:
  for command in [f'/opt/ps2/gcc/bin/ee-as {rel}/source.S -o {rel}/source.o',f'/opt/ps2/gcc/bin/ee-ld --no-check-sections -T {rel}/source.ld {rel}/source.o -o {rel}/source.elf']:
   subprocess.run(['docker','run','--rm','--platform','linux/amd64','-v',str(stage)+':/work','-w','/work',image,'bash','-lc',command],stdout=log,stderr=subprocess.STDOUT,check=True)
 elf=(scratch/'source.elf').read_bytes()
 syms=[s for s in parse_elf_function_symbols(scratch/'source.elf',section_name=None) if s.name=='_Z13func_'+address+'v']
 assert len(syms)==1
 sym=syms[0]; code=elf[sym.foff:sym.foff+sym.size];size=116 if address=='00100228' else 8
 off=int(address,16)-0x100000+0x1000; target=original[off:off+size]
 result=dict(artifact_kind='structured_startup_assembly_not_cpp_recovery',source=source.name,source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),original_elf_sha256=hashlib.sha256(original).hexdigest(),original_range_sha256=hashlib.sha256(target).hexdigest(),compiler_image=image,abi=abi,rows=[dict(address=address,symbol=sym.name,compiled_size=sym.size,target_size=size,compiled_hex=code.hex(),target_hex=target.hex(),exact_match=code==target)],linked_elf_sha256=hashlib.sha256(elf).hexdigest())
 source.with_suffix('.assembly-verification.json').write_text(json.dumps(result,indent=2)+'\n')
 print(address,sym.size,result['rows'][0]['exact_match'],flush=True)
