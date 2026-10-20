from pathlib import Path
import json
base=Path(__file__).resolve().parent
sources={}
for address in ('001c2c98','001c2ce8'):
    for marker in (0,1):
        text=(base/f'eight_hour_{address}_revisit_store_order_2.cpp').read_text()
        if marker:
            text=text.replace('u32 uVar2;', 'register u32 uVar2 asm("$14");')
        text=text.replace('*(u32 *)((u8 *)param_1 + 2748) = uVar2;', 'asm volatile("sw %1,%0" : "=m"(*(u32*)((u8*)param_1+2748)) : "r"(uVar2),"m"(*(u32*)param_1));')
        sources[f'eight_hour_{address}_v3_precise_mode_store_{marker}.cpp']=text
for address in ('00185b00','00185b70'):
    for marker in (0,1):
        text=(base/f'eight_hour_{address}_v2_table_lifetime_0.cpp').read_text()
        text=text.replace('object[700]=0;\n *object=table;', '*object=table;\n object[700]=0;')
        if marker:
            text=text.replace('object[700]=0;', '').replace('object[0x162]|=0x10;', 'object[0x162]|=0x10;\n object[700]=0;')
        if address=='00185b70':
            text=text.replace('0036c900','0036c904')
        sources[f'eight_hour_{address}_v3_zero_order_{marker}.cpp']=text
for address in ('001ae9a0','001aea00'):
    for marker in (0,1):
        text=(base/f'eight_hour_{address}_v2_field_dependencies_1.cpp').read_text().replace('*(u32*)(nested+264)=0;', '*(f32*)(nested+264)=0.0f;').replace('"m"(*(u32*)(nested+264))','"m"(*(f32*)(nested+264))')
        if marker:
            text=text.replace('register u8* nested asm("$13")=(u8*)object+1648;\n asm("" : "+r"(nested));', 'register u8* nested asm("$13");\n asm volatile("addiu %0,%1,1648" : "=r"(nested) : "r"(object),"m"(object[0x162]));')
        if address=='001aea00':
            text=text.replace('0036d858','0036d85c')
        sources[f'eight_hour_{address}_v3_float_zero_alias_{marker}.cpp']=text
for marker in (0,1):
    text=(base/'eight_hour_002d49c0_v2_float_zero_alias_1.cpp').read_text()
    text=text.replace('register f32 copied asm("$f1")=*(volatile f32*)(object+0x2fc);\n register f32* block asm("$14")=(f32*)(object+0x300);\n asm("" : "+r"(block),"+f"(copied));', 'register f32* block asm("$14")=(f32*)(object+0x300);\n asm("" : "+r"(block));\n register f32 copied asm("$f1")=*(volatile f32*)(object+0x2fc);\n asm("" : "+f"(copied));')
    if marker:
        text=text.replace('*object=table;', '*object=table;\n asm("" : "+r"(object) : "m"(*object));')
    sources[f'eight_hour_002d49c0_v3_block_dependencies_{marker}.cpp']=text
for name,text in sources.items():
    (base/name).write_text(text)
(base/'extended-constructor-v3-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_extended_constructors_v3.py').write_text((base/'probe_quad_copy.py').read_text().replace('quad-copy-variants.json','extended-constructor-v3-variants.json'))
