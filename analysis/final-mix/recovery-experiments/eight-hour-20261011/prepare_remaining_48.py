from pathlib import Path
import json
base = Path(__file__).resolve().parent
sources = {}
header = '#include "../common/types.h"\n'
for pin in (0, 1):
    text = header + 's32* func_001d3350(s32* cursor,s32 value)\n{\n s32 count=0;\n s32 current=*cursor;\n while(true){\n if(current==value)return cursor;\n ++count;\n if(count>2)break;\n current=cursor[1];\n ++cursor;\n }\n return 0;\n}\n'
    if pin:
        text = text.replace('s32 count=0;', 'register s32 count asm("$14")=0;\n asm("" : "+r"(count));')
    sources[f'eight_hour_001d3350_three_element_search_{pin}.cpp'] = text
    text = header + 'extern "C" u16 D_00372eea;\nextern "C" void func_002b4b00(void);\nextern "C" void func_0028f4d8(u32,u16,u32);\nextern "C" void func_00240be0(void);\nvoid func_0025a1d0(void)\n{\n func_002b4b00();\n func_0028f4d8(0,D_00372eea,0);\n func_00240be0();\n}\n'
    if pin:
        text = text.replace('func_0028f4d8(0,D_00372eea,0);', 'register u32 high asm("$15")=0x00370000;\n asm("" : "+r"(high));\n func_0028f4d8(0,*(u16*)(high+0x2eea),0);')
    sources[f'eight_hour_0025a1d0_halfword_forwarding_{pin}.cpp'] = text
    result = 'u32' if pin == 0 else 'u64'
    text = header + f'extern "C" u32 D_0035f21c;\nextern "C" {result} func_00139d78(u32);\n{result} func_00276df8(void)\n{{\n u32 object=D_0035f21c;\n {result} result=0;\n if(object)result=func_00139d78(object+3812);\n return result;\n}}\n'
    sources[f'eight_hour_00276df8_guarded_result_{pin}.cpp'] = text
    text = header + 'extern "C" u32 D_0035f2f8;\nextern "C" void func_00287c20(void);\nextern "C" void func_00287c78(u64);\nvoid func_00287bd0(u32 value,u64 payload)\n{\n D_0035f2f8=value;\n func_00287c20();\n func_00287c78(payload);\n}\n'
    if pin:
        text = text.replace('D_0035f2f8=value;', '(*(volatile u32*)&D_0035f2f8)=value;')
    sources[f'eight_hour_00287bd0_saved_payload_{pin}.cpp'] = text
    text = header + 'extern "C" u32 D_003617f0;\nextern "C" u32 D_003617ec;\nextern "C" void func_002b8824(u32,u64,u32,u64,u64);\nvoid func_002bd730(u32 value,u64 b,u64 c,u64 d)\n{\n D_003617f0=value;\n func_002b8824(D_003617ec,b,64,c,d);\n}\n'
    if pin:
        text = text.replace('D_003617f0=value;', '(*(volatile u32*)&D_003617f0)=value;')
    sources[f'eight_hour_002bd730_reordered_arguments_{pin}.cpp'] = text
    text = header + 'extern "C" u8* func_002dc7c8(void);\nextern "C" f32 D_00375d44;\nf32 func_002dc248(void)\n{\n u8* object=func_002dc7c8();\n'
    if pin:
        text += ' register f32* limit asm("$15")=&D_00375d44;\n asm("" : "+r"(limit));\n return *limit-*(f32*)(object+112);\n}\n'
    else:
        text += ' return D_00375d44-*(f32*)(object+112);\n}\n'
    sources[f'eight_hour_002dc248_float_difference_{pin}.cpp'] = text
    text = header + 'extern "C" f32 func_002e50f8(u32);\nextern "C" f32 D_00375db8;\nf32 func_002dd218(u32 object)\n{\n f32 value=func_002e50f8(object+256);\n'
    if pin:
        text += ' register f32* bias asm("$15")=&D_00375db8;\n asm("" : "+r"(bias));\n return -(value+*bias);\n}\n'
    else:
        text += ' return -(value+D_00375db8);\n}\n'
    sources[f'eight_hour_002dd218_float_bias_{pin}.cpp'] = text
    text = header + 'extern "C" u32 D_0033cae8[];\nbool func_002f1ae0(u32 index)\n{\n return (D_0033cae8[index>>5]&(1u<<(index&31)))!=0;\n}\n'
    if pin:
        text = text.replace('return (D_0033cae8[index>>5]&(1u<<(index&31)))!=0;', 'register u32* table asm("$15")=D_0033cae8;\n asm("" : "+r"(table));\n return (table[index>>5]&(1u<<(index&31)))!=0;')
    sources[f'eight_hour_002f1ae0_bit_predicate_{pin}.cpp'] = text
    text = header + 's32 func_00308dc0(s32* object)\n{\n s32 index=object[9]%object[6];\n object[9]=index+1;\n return object[5]+index*64;\n}\n'
    if pin:
        text = text.replace('s32 index=object[9]%object[6];', 'register s32 numerator asm("$5")=object[9];\n register s32 denominator asm("$3")=object[6];\n asm("" : "+r"(numerator),"+r"(denominator));\n s32 index=numerator%denominator;')
    sources[f'eight_hour_00308dc0_ring_index_{pin}.cpp'] = text
    text = header + 'extern "C" void func_00305a50(s32,s32*);\nvoid func_00311050(u32 value,s8 flag)\n{\n s32 payload[2];\n payload[0]=value;\n payload[1]=flag;\n func_00305a50(3,payload);\n}\n'
    if pin:
        text = text.replace('s32 payload[2];', 'struct Payload{s32 value;s32 flag;};\n Payload record;\n s32* payload=(s32*)&record;')
    sources[f'eight_hour_00311050_stack_payload_{pin}.cpp'] = text
    result = 's32' if pin == 0 else 's64'
    text = header + f'extern "C" {result} func_00311450(s32);\n{result} func_00311460(s32 value)\n{{\n if((u32)(value-13)<35)return func_00311450(value);\n return -1;\n}}\n'
    sources[f'eight_hour_00311460_checked_event_{pin}.cpp'] = text
    text = header + 'extern "C" u8 D_00348d58;\nextern "C" u8 D_00348698;\nextern "C" void func_00106420(u32*);\nvoid func_0031e068(u32* object)\n{\n object[0]=(u32)&D_00348d58;\n object[36]=(u32)&D_00348698;\n object[104]=(u32)&D_00348698;\n func_00106420(object);\n}\n'
    if pin:
        text = text.replace('object[0]=(u32)&D_00348d58;', 'register u32 second asm("$13")=(u32)&D_00348698;\n register u32 first asm("$15")=(u32)&D_00348d58;\n asm("" : "+r"(second),"+r"(first));\n object[0]=first;').replace('object[36]=(u32)&D_00348698;', 'object[36]=second;').replace('object[104]=(u32)&D_00348698;', 'object[104]=second;')
    sources[f'eight_hour_0031e068_three_vtables_{pin}.cpp'] = text
for name, text in sources.items():
    (base / name).write_text(text)
(base / 'remaining-48-variants.json').write_text(json.dumps(list(sources)))
(base / 'probe_remaining_48.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'remaining-48-variants.json'))
claim = (base / 'claim_fresh_48.py').read_text().replace('fresh-48-variants.json', 'remaining-48-variants.json').replace('fresh48-claim-', 'remaining48-claim-').replace('fresh-48-leases.json', 'remaining-48-leases.json').replace("'queuechi'", "'queuepsi'").replace("'functions': 6", "'functions': 8").replace("'instruction_bytes': 264", "'instruction_bytes': 384").replace("'exact_total': 5868", "'exact_total': 5876").replace('primary-queuechi-checkpoint', 'primary-queuepsi-checkpoint')
(base / 'claim_remaining_48.py').write_text(claim)
