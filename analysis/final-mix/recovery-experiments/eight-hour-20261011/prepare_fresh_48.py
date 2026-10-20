from pathlib import Path
import json
base = Path(__file__).resolve().parent
sources = {}
for pin in (0, 1):
    text = '#include "../common/types.h"\nu32 func_0016f770(u64 value)\n{\n'
    if pin:
        text += ' register s32 shifted asm("$2")=(s32)value>>29;\n asm("" : "+r"(shifted));\n'
    text += ' if(value>792 && (value<795 || value==1006))return 1;\n return ' + ('shifted' if pin else '((s32)value>>29)') + '&1;\n}\n'
    sources[f'eight_hour_0016f770_selected_ids_{pin}.cpp'] = text
    text = '#include "../common/types.h"\nextern "C" f32 D_01c61968;\nextern "C" u8* D_00352130;\nextern "C" void func_00191c30(f32);\nvoid func_00191bf0(f32 scalar)\n{\n'
    if pin:
        text += ' register f32 saved asm("$f0")=scalar;\n asm("" : "+f"(saved));\n'
    else:
        text += ' f32 saved=scalar;\n'
    text += ' D_01c61968=scalar;\n func_00191c30(*(f32*)(D_00352130+80)*saved);\n}\n'
    sources[f'eight_hour_00191bf0_scalar_global_{pin}.cpp'] = text
    for address, global_address, constant in (('001b83f0', '01d48cc4', '00320408'), ('001c2d48', '01d49558', '00320c08')):
        text = f'#include "../common/types.h"\nextern "C" u32* D_{global_address};\nextern "C" u8 D_{constant};\nextern "C" void func_002fd248(u64,u32*,u32,u32,u8*);\nvoid func_{address}(u64 output)\n{{\n'
        if pin:
            text += f' register u32* record asm("$5")=D_{global_address};\n register u8* callback asm("$8")=&D_{constant};\n asm("" : "+r"(record),"+r"(callback));\n'
        else:
            text += f' u32* record=D_{global_address};\n u8* callback=&D_{constant};\n'
        text += ' func_002fd248(output,record+2,record[1],8,callback);\n}\n'
        sources[f'eight_hour_{address}_record_payload_{pin}.cpp'] = text
    text = '#include "../common/types.h"\nextern "C" u32 D_01d48db8[];\nvoid func_001b9c28(u32 index)\n{\n'
    if pin:
        text += ' register u32 offset asm("$13")=(index>>5)*4;\n register u32* table asm("$15")=D_01d48db8;\n asm("" : "+r"(table));\n register u32* slot asm("$13")=(u32*)(offset+(u32)table);\n index&=31;\n *slot|=1u<<index;\n'
    else:
        text += ' D_01d48db8[index>>5]|=1u<<(index&31);\n'
    sources[f'eight_hour_001b9c28_global_bitset_{pin}.cpp'] = text + '}\n'
    text = (base / 'eight_hour_001de910_v4_cursor_dependency_0.cpp').read_text()
    text = text.replace('extern "C" void func_001de690(s32);', 'extern "C" u32 D_01d9e340;\nextern "C" void func_001dcdb8(void);').replace('extern "C" void func_001dced0(void);', 'extern "C" void func_001de808(void);').replace('void func_001de910(void)', 'void func_001de7d8(u32 value)').replace('func_001de690(0);', 'D_01d9e340=value;\n func_001dcdb8();').replace('func_001dced0();', 'func_001de808();')
    if pin:
        text = text.replace('D_01d9e340=value;', '(*(volatile u32*)&D_01d9e340)=value;')
    sources[f'eight_hour_001de7d8_stored_argument_{pin}.cpp'] = text
    for address, callee in (('002289c0', '00228918'), ('00228e28', '00228bd8')):
        text = f'#include "../common/types.h"\ntypedef void (*Callback)(u32*);\nextern "C" void func_{callee}(u32*);\nvoid func_{address}(u32* object)\n{{\n'
        if pin:
            text += ' register u32* saved asm("$16")=object;\n asm("" : "+r"(saved));\n'
        else:
            text += ' u32* saved=object;\n'
        text += f' ((Callback*)*object)[7](object);\n func_{callee}(saved);\n}}\n'
        sources[f'eight_hour_{address}_virtual_then_helper_{pin}.cpp'] = text
for name, text in sources.items():
    (base / name).write_text(text)
(base / 'fresh-48-variants.json').write_text(json.dumps(list(sources)))
(base / 'probe_fresh_48.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'fresh-48-variants.json'))
