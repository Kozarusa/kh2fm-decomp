"""Prepare fresh complete-ABI wrapper proposals after the accepted checkpoint."""
from pathlib import Path
import json,subprocess,sys
base=Path(__file__).resolve().parent;helper=base.parents[4]/'Public/tools/kh2-audit/recovery_queue.py'
sources={};header='#include "../common/types.h"\n'
for profile in range(2):
 sources[f'eight_hour_00105da8_fresh_forward_{profile}.cpp']=header+'extern "C" u32 D_0033cb84;\nextern "C" void func_00102818(u32,u64,u64,u64,u64);\nvoid func_00105da8(u64 first,u64 second,u64 third,u64 fourth)\n{\n func_00102818(D_0033cb84,first,second,third,fourth);\n}\n'
 for address,first,offset,slot,extra in [('0010c7f0','0017dbb8',2912,20,False),('0011c4b0','0011d440',20,44,True)]:
  typ='u32' if profile else 'void';args='u32*,u32*' if extra else 'u32*';actual='receiver,object' if extra else 'receiver'
  text=header+f'extern "C" void func_{first}(u32*);\nvoid func_{address}(u32* object)\n{{\n func_{first}(object);\n u32* receiver=(u32*)object[{offset//4}];\n typedef {typ} (*Callback)({args});\n'
  expression=f'((Callback)(*(u32**)*receiver)[{slot//4}])({actual})'
  text+=(' u32 result='+expression+';\n asm("" : : "r"(result));\n' if profile else ' '+expression+';\n')+'}\n'
  sources[f'eight_hour_{address}_fresh_virtual_{profile}.cpp']=text
 typ='u32' if profile else 'void'
 text=header+'extern "C" u32* func_001050c8();\nvoid func_0015b4c0(u64 payload)\n{\n u32* receiver=func_001050c8();\n'+f' typedef {typ} (*Callback)(u32*,u64);\n'
  # Native preserves the full incoming payload in the second callback argument.
 expression='((Callback)(*(u32**)*receiver)[1])(receiver,payload)'
 text+=(' u32 result='+expression+';\n asm("" : : "r"(result));\n' if profile else ' '+expression+';\n')+'}\n'
 sources[f'eight_hour_0015b4c0_fresh_virtual_{profile}.cpp']=text
 for address,delta,value in [('00262730',2504,242),('0027d450',0,234)]:
  word='u32' if profile else 'u64';add=f'+{delta}' if delta else ''
  sources[f'eight_hour_{address}_fresh_three_calls_{profile}.cpp']=header+f'extern "C" {word} func_00257770();\nextern "C" u32 func_00139d78({word});\nextern "C" void func_0028da70({word},s32);\nvoid func_{address}()\n{{\n {word} object=func_00257770(){add};\n func_00139d78(object);\n func_0028da70(object,{value});\n}}\n'
 text=header+'extern "C" void func_00139768();\nextern "C" void func_001394c0(u64);\nextern "C" void func_00102750(u32);\nextern "C" u32* D_00347f80;\nvoid func_001394d8(u64 payload)\n{\n func_00139768();\n func_001394c0(payload);\n func_00102750(*D_00347f80);\n}\n'
 sources[f'eight_hour_001394d8_fresh_three_calls_{profile}.cpp']=text
 sources[f'eight_hour_003206f0_fresh_subobject_{profile}.cpp']=header+f'extern "C" u8 D_00351228;\nextern "C" void func_001d48b0(u32*);\nextern "C" void func_00106420(u32*);\nvoid func_003206f0(u32* object)\n{{\n *({"volatile " if profile else ""}u32*)object=(u32)&D_00351228;\n func_001d48b0(object+0x270);\n func_00106420(object);\n}}\n'
for profile in range(4):
 word='u64' if profile&1 else 'u32';index='s32' if profile&2 else 'u32'
 sources[f'eight_hour_0011f238_fresh_virtual_index_{profile}.cpp']=header+f's16 func_0011f238(u32* object,{index} index)\n{{\n typedef {word} (*Callback)(u32*);\n {word} base=((Callback)(*(u32**)*object)[8])(object);\n return *(s16*)((u32)base+index*64+4);\n}}\n'
for profile in range(2):
 qualifier='volatile ' if profile else ''
 sources[f'eight_hour_00137c50_fresh_initialization_{profile}.cpp']=header+f'extern "C" void func_001391c8(u32*,u32,u32);\nvoid func_00137c50(u32* object)\n{{\n {qualifier}u32* fields=object;\n fields[0xa72]=0;\n fields[0xa70]=1;\n fields[8]=1;\n fields[12]=0;\n fields[13]=0;\n fields[0xa71]=0;\n func_001391c8(object,0x2b5c,0);\n}}\n'
 sources[f'eight_hour_002cb7c8_fresh_quad_copy_{profile}.cpp']=header+'struct Quad { u32 words[4]; };\nextern "C" Quad* func_002cb890(u64,u64);\nQuad* func_002cb7c8(Quad* output,u64 second,u64 third)\n{\n Quad* input=func_002cb890(second,third);\n'+(' asm volatile("lq $8,0(%1)\\n\\tsq $8,0(%0)" : "=m"(*output) : "r"(input),"r"(output),"m"(*input) : "$8");\n' if profile else ' *output=*input;\n')+' return output;\n}\n'
  # The memory operand occupies %0; register references must address output explicitly.
 if profile:sources[f'eight_hour_002cb7c8_fresh_quad_copy_{profile}.cpp']=sources[f'eight_hour_002cb7c8_fresh_quad_copy_{profile}.cpp'].replace('sq $8,0(%0)','sq $8,0(%2)')
leases=[]
for address in sorted({name.split('_')[2] for name in sources}):
 result=subprocess.run([sys.executable,str(helper),'claim','--worker','eight-hour-primary','--count','1','--address',address],capture_output=True,text=True,check=True)
 selected=json.loads(result.stdout)['leases'];assert len(selected)==1,address;leases.extend(selected)
for name,text in sources.items():
 assert not(base/name).exists();(base/name).write_text(text)
with (base/'fresh56-leases.json').open('x') as stream:json.dump(leases,stream,indent=2)
(base/'fresh56-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_fresh56.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','fresh56-variants.json'))
(base/'harvest_fresh56.py').write_text((base/'harvest_extended_constructors.py').read_text().replace('extended-constructor-leases.json','fresh56-leases.json'))
record_path=base.parents[1]/'worker-coordination/eight-hour-run-20261011.json';record=json.loads(record_path.read_text())
assert not any(r['phase']=='queuedeltaprime' for r in record['accepted_batches'])
record['accepted_batches'].append({'phase':'queuedeltaprime','functions':5,'instruction_bytes':528,'exact_total':5973,'checkpoint':'primary-queuedeltaprime-checkpoint-2026-10-08.json'})
record['phase']='fresh-medium-call-wrappers';record_path.write_text(json.dumps(record,indent=2)+'\n')
print(f'Claimed {len(leases)} targets; prepared {len(sources)} proposals.')
