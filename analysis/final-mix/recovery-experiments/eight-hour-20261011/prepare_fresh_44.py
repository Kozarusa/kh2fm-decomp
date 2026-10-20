from pathlib import Path
import json
base = Path(__file__).resolve().parent
sources = {}
for pin in (0, 1):
    text = '#include "../common/types.h"\nextern "C" u8 D_004f3700[];\nvoid func_0015cbb8(u8 a,u8 b,u8 c,u8 d)\n{\n'
    if pin:
        text += ' register u8* cursor asm("$15")=D_004f3700;\n asm("" : "+r"(cursor));\n D_004f3700[0]=a;\n cursor[1]=b;\n cursor[3]=d;\n cursor[2]=c;\n'
    else:
        text += ' D_004f3700[0]=a;\n D_004f3700[1]=b;\n D_004f3700[3]=d;\n D_004f3700[2]=c;\n'
    sources[f'eight_hour_0015cbb8_bytes_{pin}.cpp'] = text + '}\n'
    text = '#include "../common/types.h"\nbool func_001c0268(u32 object,u32 other)\n{\n'
    if pin:
        text += ' register u32 index asm("$15")=*(u32*)(other+28);\n register u32 mask asm("$14")=1;\n asm("" : "+r"(mask));\n register u32 offset asm("$13")=(index>>5)*4;\n index&=31;\n object+=offset;\n mask<<=index;\n return (*(u32*)(object+4)&mask)==0;\n'
    else:
        text += ' u32 index=*(u32*)(other+28);\n return (*(u32*)(object+(index>>5)*4+4)&(1u<<(index&31)))==0;\n'
    sources[f'eight_hour_001c0268_bit_table_{pin}.cpp'] = text + '}\n'
    text = '#include "../common/types.h"\nextern "C" s8* D_0035ec94;\nextern "C" void func_00240c08(s32,u32,s32);\nvoid func_00241740(s32 value)\n{\n if(value<0)value=D_0035ec94[1];\n func_00240c08(value,0,19);\n}\n'
    if pin:
        text = text.replace('if(value<0)value=D_0035ec94[1];', 'if(value<0){register s8* object asm("$14")=D_0035ec94;asm("" : "+r"(object));value=object[1];}')
    sources[f'eight_hour_00241740_signed_payload_{pin}.cpp'] = text
    text = '#include "../common/types.h"\nextern "C" u32 D_0035f028;\nextern "C" void func_00139d78(u32);\nvoid func_00256b80(s32 index)\n{\n register s32 stride asm("$15")=408;\n asm("" : "+r"(stride));\n register s32 offset asm("$13")=index*stride;\n'
    if pin:
        text += ' asm("" : "+r"(offset));\n'
    text += ' func_00139d78(D_0035f028+offset);\n}\n'
    sources[f'eight_hour_00256b80_stride_{pin}.cpp'] = text
    text = '#include "../common/types.h"\nextern "C" u32 D_01d9e348[];\nextern "C" void func_001de690(s32);\nextern "C" void func_001dced0(void);\nvoid func_001de910(void)\n{\n func_001de690(0);\n'
    if pin:
        text += ' register u32* cursor asm("$14")=D_01d9e348;\n asm("" : "+r"(cursor));\n D_01d9e348[0]=0;\n cursor[1]=0;\n'
    else:
        text += ' D_01d9e348[0]=0;\n D_01d9e348[1]=0;\n'
    sources[f'eight_hour_001de910_clear_pair_{pin}.cpp'] = text + ' func_001dced0();\n}\n'
    text = '#include "../common/types.h"\nextern "C" u8 D_00348d58;\nextern "C" u8 D_00348698;\nextern "C" void func_00106420(u32*);\nvoid func_0031e0b8(u32* object)\n{\n'
    if pin:
        text += ' register u32 first asm("$14")=(u32)&D_00348d58;\n register u32 second asm("$13")=(u32)&D_00348698;\n asm("" : "+r"(first),"+r"(second));\n object[0]=first;\n object[20]=second;\n'
    else:
        text += ' object[0]=(u32)&D_00348d58;\n object[20]=(u32)&D_00348698;\n'
    sources[f'eight_hour_0031e0b8_double_vtable_{pin}.cpp'] = text + ' func_00106420(object);\n}\n'
for name, text in sources.items():
    (base / name).write_text(text)
(base / 'fresh-44-variants.json').write_text(json.dumps(list(sources)))
(base / 'probe_fresh_44.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'fresh-44-variants.json'))
