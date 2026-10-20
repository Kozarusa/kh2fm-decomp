"""Recover observed 64-bit stores and signed/unsigned halfword transport."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
variants = []
for target_volatile in [False, True]:
    target = 'volatile ' if target_volatile else ''
    source = '#include "../common/types.h"\n' + f'extern "C" {target}u64* volatile D_0035f324;\n'
    source += 'void func_00288018(void){D_0035f324[0]=0;D_0035f324[1]=0;D_0035f324[2]=0;D_0035f324[3]=0;}\n'
    variants.append((f'00288018_width64_{int(target_volatile)}', source))
variants.append(('001d97c8_halfword_direct', '#include "../common/types.h"\nextern "C" u16 D_0032fb00;\nvoid func_001d97c8(void){if(D_0032fb00<999)++D_0032fb00;}\n'))
for profile in ['plain', 'count_transport']:
    source = '#include "../common/types.h"\nextern "C" u16 D_0032fafe[];\nvoid func_001d97c8(void)\n{\n register u16* slots asm("$14")=D_0032fafe;asm("" : "+r"(slots));\n'
    if profile == 'plain':
        source += ' u16 count=slots[1];if(count<999)slots[1]=count+1;\n'
    else:
        source += ' register u32 count asm("$15")=slots[1];\n register u32 next asm("$13")=count+1;\n asm("" : "+r"(count) : "r"(next));\n if((u16)count<999)slots[1]=(u16)next;\n'
    source += '}\n'
    variants.append((f'001d97c8_halfword_{profile}', source))
for normalized in [False, True]:
    for shared_pointer in [False, True]:
        source = '#include "../common/types.h"\n'
        if normalized:
            source += 'void func_0023e738(u32 object,u32 index,u32 firstWord,u32 secondWord)\n{\n register s32 first asm("$6")=(s16)firstWord;register s32 second asm("$7")=(s16)secondWord;\n asm("" : "+r"(first),"+r"(second));\n'
        else:
            source += 'void func_0023e738(u32 object,u32 index,s16 first,s16 second)\n{\n'
        source += ' register u32 indexed asm("$5")=object+index*2;\n'
        if shared_pointer:
            source += ' register u32 pair asm("$15")=indexed+0xb70;\n asm("" : "+r"(pair));\n *(s16*)(indexed+0xb70)=first;*(s16*)(pair+8)=second;\n'
        else:
            source += ' *(s16*)(indexed+0xb70)=first;*(s16*)(indexed+0xb78)=second;\n'
        source += '}\n'
        variants.append((f'0023e738_signed_{int(normalized)}_{int(shared_pointer)}', source))
names = []
for tag, source in variants:
    name = f'eight_hour_{tag}.cpp'
    path = base / name
    assert not path.exists()
    path.write_text(source)
    names.append(name)
(base / 'native-width-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_native_widths.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'native-width-variants.json'"))
print(f'Prepared {len(names)} original-width transport profiles.')
