from pathlib import Path
import json
base=Path(__file__).resolve().parent
sources={}
for address in ('001358c0','00135900'):
    text=(base/f'eight_hour_{address}_linked_head_0.cpp').read_text().replace('u32* D_00347cf0','u32 D_00347cf0').replace('(u32)D_00347cf0','D_00347cf0').replace('D_00347cf0=object;','D_00347cf0=(u32)object;')
    sources[f'eight_hour_{address}_v2_integer_head.cpp']=text
    text=f'#include "../common/types.h"\nstruct Node{{u32 table;u32 reserved;Node* next;}};\nextern "C" u8 D_00347d00;\nextern "C" Node* D_00347cf0;\nextern "C" void func_00135aa0(Node*);\nvoid func_{address}(Node* object)\n{{\n object->table=(u32)&D_00347d00;\n func_00135aa0(object);\n object->next=D_00347cf0;\n D_00347cf0=object;\n}}\n'
    sources[f'eight_hour_{address}_v2_pointer_field.cpp']=text
text=(base/'eight_hour_002ee5d8_subobject_payload_0.cpp').read_text().replace('u32*,u64','u32*,u32').replace('u32* object,u64 payload','u32* object,u32 payload').replace('(u32)payload','payload')
sources['eight_hour_002ee5d8_v2_word_payload.cpp']=text
for index in (0,1):
    text=(base/'eight_hour_002c1aa0_three_argument_constructor_0.cpp').read_text()
    marker='asm("" : "+m"(object[0x2b9]),"+m"(*(u8*)(object+0x2ba)));' if index==0 else 'asm("" : "+m"(object[0x2b9]),"+m"(*(u8*)(object+0x2ba)),"+m"(object[0]));'
    text=text.replace('object[0x2b9]=0;', 'object[0x2b9]=0;\n '+marker)
    sources[f'eight_hour_002c1aa0_v2_clear_order_{index}.cpp']=text
for address,global_address in (('0014ba20','0036b0d8'),('0014ba90','0036b0e0')):
    for marker in (0,1):
        text=f'#include "../common/types.h"\nextern "C" u8 D_00349da8;\nextern "C" u64 D_{global_address};\nextern "C" void func_0014b290(u32*);\nvoid func_{address}(u32* object)\n{{\n func_0014b290(object);\n u64 data=D_{global_address};\n register u64 flags asm("$14")=1ULL<<60;\n asm("" : "+r"(flags));\n *(u64*)(object+0x42)=14;\n *(u64*)(object+0x44)=data;\n *(u64*)(object+0x40)=flags|0x8001;\n *(u64*)(object+0x46)=64;\n *object=(u32)&D_00349da8;\n'
        if marker:
            text+=' asm("" : : : "memory");\n'
        text+=' *(u64*)(object+0x48)=flags|0x8001;\n *(u64*)(object+0x4a)=14;\n *(u64*)(object+0x4c)=data;\n *(u64*)(object+0x4e)=64;\n}\n'
        sources[f'eight_hour_{address}_v2_packed_groups_{marker}.cpp']=text
for name,text in sources.items():
    (base/name).write_text(text)
(base/'constructor-abi-v2-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_constructor_abis_v2.py').write_text((base/'probe_quad_copy.py').read_text().replace('quad-copy-variants.json','constructor-abi-v2-variants.json'))
