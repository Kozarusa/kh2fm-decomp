from pathlib import Path
import json
base=Path(__file__).resolve().parent;sources={}
for address in ('002d96d8','002d9730'):
 for profile in range(8):
  text='#include "../common/types.h"\nextern "C" u8 D_003625e0;\nextern "C" void func_002d0ea8(u32*,u64,u64,u64);\n'+f'void func_{address}(u32* object,u64 second,u64 third,u64 fourth)\n{{\n func_002d0ea8(object,second,third,fourth);\n'
  if profile&4:text+=' register u32 table asm("$15")=(u32)&D_003625e0;\n asm("" : "+r"(table));\n'
  text+=' object[0x326]=0;\n'
  if profile&2:text+=' register u32 one asm("$14")=1;\n asm("" : "+r"(one) : "m"(object[0x326]));\n'
  zero=' *(f32*)(object+0x2fc)=0.0f;\n' if profile&1 else ' object[0x2fc]=0;\n'
  text+=zero+f' *(u8*)(object+0x301)={"one" if profile&2 else "1"};\n'+(' *object=table;\n' if profile&4 else ' *object=(u32)&D_003625e0;\n')
  text+=(' *(f32*)(object+0x2fd)=0.0f;\n' if profile&1 else ' object[0x2fd]=0;\n')+f' *(u8*)(object+0x2ff)={"one" if profile&2 else "1"};\n object[0x300]=0;\n object[0x324]=0;\n object[0x325]=0;\n}}\n'
  sources[f'eight_hour_{address}_byte_float_constructor_{profile}.cpp']=text
for name,text in sources.items():
 assert not(base/name).exists();(base/name).write_text(text)
(base/'byte-float-constructor-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_byte_float_constructors.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','byte-float-constructor-variants.json'))
