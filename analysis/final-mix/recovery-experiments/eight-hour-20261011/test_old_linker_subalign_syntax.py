from pathlib import Path
import subprocess,json
stage=Path('/root/kh2fm-build');out=stage/'out/alignment-diagnostic'
obj='out/build/src/anon/fm_primary_queuekappaprime_recovered_002b6b84.o';symbol='_Z13func_002b6b84Pv'
variants={'before_colon':f'.callee 0x2b6b84 SUBALIGN(4) : {{ *(.text.{symbol}) }}','after_body':f'.callee 0x2b6b84 : {{ *(.text.{symbol}) }} SUBALIGN(4)','inside_body':f'.callee 0x2b6b84 : {{ SUBALIGN(4); *(.text.{symbol}) }}'}
for name,section in variants.items():
 p=out/(name+'.ld');assert not p.exists();p.write_text('INCLUDE out/generated/symbols.ld\nSECTIONS { '+section+' .rest 0x400000 : { *(*) } }\n')
 cmd=['docker','run','--rm','--platform','linux/amd64','-v',f'{stage}:/work','-w','/work','kh2-local/ps2-compiler:3.2-ee-040921-objdiff','/opt/ps2/gcc/bin/ee-ld','--no-check-sections','-T',str(p.relative_to(stage)),obj,'-o',str((out/(name+'.elf')).relative_to(stage))]
 r=subprocess.run(cmd,capture_output=True,text=True);(out/(name+'.log')).write_text(r.stdout+r.stderr);print(name,r.returncode,r.stderr[:500],flush=True)
