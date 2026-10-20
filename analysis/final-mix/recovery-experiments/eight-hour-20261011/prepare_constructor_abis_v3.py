from pathlib import Path
import json
base=Path(__file__).resolve().parent
sources={}
for address in ('0014ba20','0014ba90'):
    for marker in (0,1):
        text=(base/f'eight_hour_{address}_v2_packed_groups_0.cpp').read_text()
        text=text.replace('extern "C" u8 D_00349da8;', 'struct PackedBlock{u64 words[4];};\nextern "C" u8 D_00349da8;')
        expression='asm("" : "+m"(*(PackedBlock*)(object+0x40)),"+m"(*(PackedBlock*)(object+0x48)));' if marker==0 else 'asm("" : : "m"(*(PackedBlock*)(object+0x40)),"m"(*(PackedBlock*)(object+0x48)));'
        text=text.replace('*object=(u32)&D_00349da8;', '*object=(u32)&D_00349da8;\n '+expression)
        sources[f'eight_hour_{address}_v3_precise_groups_{marker}.cpp']=text
for marker in (0,1):
    text=(base/'eight_hour_002c1aa0_v2_clear_order_1.cpp').read_text()
    text=text.replace('object[0x2b9]=0;', 'register u32 table asm("$15")=(u32)&D_00361b20;\n asm("" : "+r"(table) : "m"(object[0x2b9]));\n object[0x2b9]=0;').replace('*(u32*)object=(u32)&D_00361b20;', '*(u32*)object=table;')
    if marker:
        text=text.replace('asm("" : "+m"(object[0x2b9]),"+m"(*(u8*)(object+0x2ba)),"+m"(object[0]));', '')
    sources[f'eight_hour_002c1aa0_v3_table_dependency_{marker}.cpp']=text
for name,text in sources.items():
    (base/name).write_text(text)
(base/'constructor-abi-v3-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_constructor_abis_v3.py').write_text((base/'probe_quad_copy.py').read_text().replace('quad-copy-variants.json','constructor-abi-v3-variants.json'))
