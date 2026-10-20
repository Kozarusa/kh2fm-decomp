from pathlib import Path
import json
base=Path(__file__).resolve().parent
sources={}
for address in ('001c2c98','001c2ce8'):
    for marker in (0,1):
        text=(base/f'eight_hour_{address}_revisit_store_order_2.cpp').read_text()
        expression='asm("" : "+r"(uVar2) : "m"(*(u32*)param_1));' if marker==0 else 'asm("" : "+r"(param_1) : "m"(*(u32*)param_1));'
        text=text.replace('*(u32 *)param_1 = (u32)&D_00351468;', '*(u32 *)param_1 = (u32)&D_00351468;\n '+expression)
        sources[f'eight_hour_{address}_v2_final_mode_dependency_{marker}.cpp']=text
for address in ('00185b00','00185b70'):
    for marker in (0,1):
        text=(base/f'eight_hour_{address}_inherited_float_constructor_1.cpp').read_text()
        text=text.replace('object[700]=0;', 'register u32 table asm("$15")=(u32)&D_0034ed78;\n asm("" : "+r"(table) : "m"(object[700]));\n object[700]=0;').replace('*object=(u32)&D_0034ed78;', '*object=table;')
        if marker:
            text=text.replace('*object=table;', '*(volatile u32*)object=table;')
        sources[f'eight_hour_{address}_v2_table_lifetime_{marker}.cpp']=text
for address in ('001ae9a0','001aea00'):
    for marker in (0,1):
        text=(base/f'eight_hour_{address}_nested_float_constructor_1.cpp').read_text()
        text=text.replace('*object=(u32)&D_00350ce0;\n object[0x162]|=0x400;', 'register u32 table asm("$15")=(u32)&D_00350ce0;\n register u32 flags asm("$14")=object[0x162];\n asm("" : "+r"(table),"+r"(flags));\n *object=table;\n asm("" : "+r"(flags) : "m"(*object));\n object[0x162]=flags|0x400;')
        text=text.replace('asm("" : "+r"(scale));', 'asm("" : "+r"(scale) : "m"(*(u32*)(nested+264)));')
        if marker:
            text=text.replace('object[0x2af]|=0x8404;', 'asm("" : "+r"(object) : "m"(*(f32*)(nested+260)));\n register u32 mode asm("$15")=object[0x2af];\n asm("" : "+r"(mode));\n object[0x2af]=mode|0x8404;')
        sources[f'eight_hour_{address}_v2_field_dependencies_{marker}.cpp']=text
for marker in (0,1):
    text=(base/'eight_hour_002d49c0_float_block_constructor_1.cpp').read_text().replace('object[0x2fc]=0;', '*(f32*)(object+0x2fc)=0.0f;')
    if marker:
        text=text.replace('*(f32*)(object+0x2fc)=0.0f;', 'register u32 table asm("$15")=(u32)&D_003622c0;\n asm("" : "+r"(table));\n *(f32*)(object+0x2fc)=0.0f;').replace('*object=(u32)&D_003622c0;', '*object=table;')
    sources[f'eight_hour_002d49c0_v2_float_zero_alias_{marker}.cpp']=text
text=(base/'eight_hour_00127f40_buffer_constructor_0.cpp').read_text()
text=text.replace('u32 buffer=origin+*(volatile u16*)(header+18)*64;', 'u32 endAgain=*(volatile u16*)(header+18);\n register u32 stride asm("$14")=count*64;\n asm("" : "+r"(stride));\n register u32 buffer asm("$15")=origin+endAgain*64;\n asm("" : "+r"(buffer));')
text=text.replace('object[4]=buffer+count*64;\n object[5]=buffer+count*64+count*64;', 'register u32 next asm("$12")=buffer+stride;\n asm("" : "+r"(next));\n object[4]=next;\n object[5]=next+stride;')
sources['eight_hour_00127f40_v2_buffer_dependencies.cpp']=text
for name,text in sources.items():
    (base/name).write_text(text)
(base/'extended-constructor-v2-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_extended_constructors_v2.py').write_text((base/'probe_quad_copy.py').read_text().replace('quad-copy-variants.json','extended-constructor-v2-variants.json'))
