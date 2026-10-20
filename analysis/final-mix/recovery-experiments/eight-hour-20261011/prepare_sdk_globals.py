from pathlib import Path
import json
base = Path(__file__).resolve().parent
names = []
for pin in (0, 1):
    name = f'eight_hour_002e2e18_conditional_callback_{pin}.cpp'
    text = '#include "../common/types.h"\nextern "C" u32 D_00361f60;\nextern "C" void func_002ceb08(void);\nu32 func_002e2e18(void)\n{\n register u32 saved asm("$16")=D_00361f60;\n'
    if pin:
        text += ' asm("" : "+r"(saved));\n'
    text += ' if(saved!=0)func_002ceb08();\n return *(u32*)(saved+264);\n}\n'
    (base / name).write_text(text)
    names.append(name)
for pin in (0, 1):
    name = f'eight_hour_00308650_corrected_global_{pin}.cpp'
    text = '#include "../common/types.h"\nextern "C" u32 D_01e357d4;\nextern "C" u32 D_003660d8;\nextern "C" void func_003061d0(u32);\nextern "C" void func_00305350(u32,u32);\nvoid func_00308650(void)\n{\n func_003061d0(5);\n'
    if pin:
        text += ' register u32 address asm("$3")=0x01e30000;\n asm("" : "+r"(address));\n func_00305350(5,*(u32*)(address+0x57d4));\n register u32 dest asm("$3")=0x00360000;\n asm("" : "+r"(dest));\n *(u32*)(dest+0x60d8)=0;\n'
    else:
        text += ' func_00305350(5,D_01e357d4);\n D_003660d8=0;\n'
    text += '}\n'
    (base / name).write_text(text)
    names.append(name)
for pin in (0, 1):
    name = f'eight_hour_0030a690_symbol_address_{pin}.cpp'
    text = '#include "../common/types.h"\nextern "C" u32 D_00366164;\nextern "C" u8 D_01e389a8;\nextern "C" void func_002fde18(u8*,u32,u32);\nu32 func_0030a690(void)\n{\n'
    if pin:
        text += ' register u32 address asm("$2")=0x00360000;\n asm("" : "+r"(address));\n *(u32*)(address+0x6164)=0;\n'
    else:
        text += ' D_00366164=0;\n'
    text += ' func_002fde18(&D_01e389a8,0,4);\n return 0;\n}\n'
    (base / name).write_text(text)
    names.append(name)
(base / 'sdk-global-variants.json').write_text(json.dumps(names))
(base / 'probe_sdk_globals.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'sdk-global-variants.json'))
