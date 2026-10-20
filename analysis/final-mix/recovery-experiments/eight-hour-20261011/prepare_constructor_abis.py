"""Propose complete object and payload forwarding from the observed register ABI."""
from pathlib import Path
import json
import subprocess
import sys
base=Path(__file__).resolve().parent
helper=base.parents[4]/'Public/tools/kh2-audit/recovery_queue.py'
sources={}
header='#include "../common/types.h"\n'
for row in json.loads((base/'initializing-wrapper-census.json').read_text()):
    if row['accepted'] or row['state']!=['ready','general']:
        continue
    address=row['address']
    for profile in (0,1):
        qualifier='volatile ' if profile else ''
        text=header+f'extern "C" u8 D_{row["vtable"]};\nextern "C" void func_{row["first_helper"]}(u32*);\nextern "C" void func_{row["final_helper"]}(u32*);\nvoid func_{address}(u32* object)\n{{\n func_{row["first_helper"]}(object);\n *({qualifier}u32*)object=(u32)&D_{row["vtable"]};\n func_{row["final_helper"]}(object);\n}}\n'
        sources[f'eight_hour_{address}_initializing_wrapper_{profile}.cpp']=text
for profile in (0,1):
    qualifier='volatile ' if profile else ''
    for address in ('001358c0','00135900'):
        text=header+f'extern "C" u8 D_00347d00;\nextern "C" u32* D_00347cf0;\nextern "C" void func_00135aa0(u32*);\nvoid func_{address}(u32* object)\n{{\n *object=(u32)&D_00347d00;\n func_00135aa0(object);\n *({qualifier}u32*)(object+2)=(u32)D_00347cf0;\n D_00347cf0=object;\n}}\n'
        sources[f'eight_hour_{address}_linked_head_{profile}.cpp']=text
    for address,global_address in (('0014ba20','0036b0d8'),('0014ba90','0036b0e0')):
        text=header+f'extern "C" u8 D_00349da8;\nextern "C" u64 D_{global_address};\nextern "C" void func_0014b290(u32*);\nvoid func_{address}(u32* object)\n{{\n func_0014b290(object);\n u64 data=D_{global_address};\n *({qualifier}u64*)(object+0x42)=14;\n *({qualifier}u64*)(object+0x44)=data;\n *({qualifier}u64*)(object+0x40)=0x1000000000008001ULL;\n *({qualifier}u64*)(object+0x46)=64;\n *object=(u32)&D_00349da8;\n *({qualifier}u64*)(object+0x48)=0x1000000000008001ULL;\n *({qualifier}u64*)(object+0x4a)=14;\n *({qualifier}u64*)(object+0x4c)=data;\n *({qualifier}u64*)(object+0x4e)=64;\n}}\n'
        sources[f'eight_hour_{address}_packed_blocks_{profile}.cpp']=text
    for address in ('001ad5a8','001ad5f0'):
        text=header+f'extern "C" u8 D_00350a70;\nextern "C" u8 D_00350a56;\nextern "C" void func_001ad280(u32*,u64);\nextern "C" void func_001c1130(s32);\nextern "C" void func_0014c9d8(s32);\nvoid func_{address}(u32* object,u64 payload)\n{{\n func_001ad280(object,payload);\n *({qualifier}u32*)object=(u32)&D_00350a70;\n D_00350a56=1;\n func_001c1130(12);\n func_0014c9d8(8);\n}}\n'
        sources[f'eight_hour_{address}_constructor_payload_{profile}.cpp']=text
    for address in ('001db8f8','001db950'):
        text=header+f'extern "C" u8 D_00352a78;\nextern "C" void func_001c23a8(u32*,u64,u64,u64,u64,u64,u64);\nvoid func_{address}(u32* object,u64 second,u64 third,u64 fourth)\n{{\n func_001c23a8(object,second,third,0,0,96,fourth);\n object[0x27e]=0;\n object[0x162]|=0x10000000;\n *({qualifier}u32*)object=(u32)&D_00352a78;\n}}\n'
        sources[f'eight_hour_{address}_seven_argument_constructor_{profile}.cpp']=text
    text=header+f'extern "C" u8 D_00361b20;\nextern "C" void func_002be770(u32*,u64,u64);\nvoid func_002c1aa0(u32* object,u64 second,u64 third)\n{{\n func_002be770(object,second,third);\n object[0x2b9]=0;\n *({qualifier}u32*)object=(u32)&D_00361b20;\n object[0x163]|=1;\n *(u8*)(object+0x2ba)=0;\n}}\n'
    sources[f'eight_hour_002c1aa0_three_argument_constructor_{profile}.cpp']=text
    text=header+f'extern "C" u8 D_00363828;\nextern "C" void func_002edf28(u32*);\nextern "C" void func_001ad330(u32*,u64);\nvoid func_002ee5d8(u32* object,u64 payload)\n{{\n func_002edf28(object);\n object[10]=(u32)payload;\n object[9]=0;\n *({qualifier}u32*)object=(u32)&D_00363828;\n func_001ad330(object+11,payload);\n}}\n'
    sources[f'eight_hour_002ee5d8_subobject_payload_{profile}.cpp']=text
leases=[]
for address in sorted({name.split('_')[2] for name in sources}):
    result=subprocess.run([sys.executable,str(helper),'claim','--worker','eight-hour-primary','--count','1','--address',address],capture_output=True,text=True)
    assert result.returncode==0,result.stdout+result.stderr
    claimed=json.loads(result.stdout)['leases']
    assert len(claimed)==1,address
    leases.extend(claimed)
for name,text in sources.items():
    (base/name).write_text(text)
with (base/'constructor-abi-leases.json').open('x') as stream:
    json.dump(leases,stream,indent=2)
(base/'constructor-abi-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_constructor_abis.py').write_text((base/'probe_quad_copy.py').read_text().replace('quad-copy-variants.json','constructor-abi-variants.json'))
print(f'Claimed {len(leases)} functions; prepared {len(sources)} complete ABI proposals.')
