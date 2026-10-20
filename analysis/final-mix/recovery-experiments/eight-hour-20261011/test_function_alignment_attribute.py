from pathlib import Path
import subprocess,json,struct
stage=Path('/root/kh2fm-build');out=stage/'out/alignment-diagnostic';source=stage/'src/anon/fm_primary_queuekappaprime_recovered_002b6b84.cpp'
text=source.read_text();needle='u64 func_002b6b84(u32 input) asm("_Z13func_002b6b84Pv");';assert needle in text
for alignment in (4,1):
 name=f'function-aligned-{alignment}';cpp=out/(name+'.cpp');assert not cpp.exists();cpp.write_text(text.replace(needle,needle+'\nu64 func_002b6b84(u32 input) __attribute__((aligned('+str(alignment)+')));'))
 cmd=['docker','run','--rm','--platform','linux/amd64','-v',f'{stage}:/work','-w','/work','kh2-local/ps2-compiler:3.2-ee-040921-objdiff','/opt/ps2/gcc/bin/ee-g++','-O2','-g0','-x','c++','-fno-exceptions','-fno-rtti','-fpermissive','-ffunction-sections','-Iinclude','-c',str(cpp.relative_to(stage)),'-o',str((out/(name+'.o')).relative_to(stage))]
 r=subprocess.run(cmd,capture_output=True,text=True);(out/(name+'.log')).write_text(r.stdout+r.stderr);print(name,r.returncode,r.stderr,flush=True)
 if r.returncode:continue
 data=(out/(name+'.o')).read_bytes();off=struct.unpack_from('<I',data,0x20)[0];ent,num,index=struct.unpack_from('<HHH',data,0x2e);headers=[struct.unpack_from('<10I',data,off+i*ent) for i in range(num)];sh=headers[index];strings=data[sh[4]:sh[4]+sh[5]]
 for sh in headers:
  section=strings[sh[0]:].split(b'\0',1)[0].decode()
  if '002b6b84' in section:print(section,'alignment',sh[8],'size',sh[5],flush=True)
