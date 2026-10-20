from pathlib import Path
import json
base=Path(__file__).resolve().parent;names=[]
for profile in range(6):
 arg='double value' if profile>=4 else ('s64 bits' if profile&2 else 'u64 bits')
 text='#include "../common/types.h"\n'+f'u32 func_00304db0({arg})\n{{\n'
 if profile>=4:text+=' union Raw { double value; u64 bits; };\n Raw raw;\n raw.value=value;\n u64 bits=raw.bits;\n'
 word='s32' if profile&1 else 'u32'
 text+=f' {word} high=({word})(bits>>32);\n {word} low=({word})bits;\n high&=0x7fffffff;\n high|=(u32)(low|(-low))>>31;\n high=0x7ff00000-high;\n return (u32)high>>31;\n}}\n'
 name=f'eight_hour_00304db0_v4_native_word_extraction_{profile}.cpp';assert not(base/name).exists();(base/name).write_text(text);names.append(name)
(base/'double-classification-v4-variants.json').write_text(json.dumps(names))
(base/'probe_double_classification_v4.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','double-classification-v4-variants.json'))
