from pathlib import Path
import json
base=Path(__file__).resolve().parent
sources={}
for address in ('00185b00','00185b70'):
 for profile in range(4):
  text=(base/f'eight_hour_{address}_v5_receiver_transport_{profile%2}.cpp').read_text()
  global_name='D_0036c900' if address=='00185b00' else 'D_0036c904'
  old=f' register f32* scale asm("$15")=&{global_name};\n asm("" : "+r"(scale));'
  low=-14080 if address=='00185b00' else -14076
  if profile//2:
   new=f' register u32 high asm("$15");\n asm("lui %0,0x37" : "=r"(high) : "r"(receiver));\n register f32* scale asm("$15")=(f32*)(high+({low}));\n asm("" : "+r"(scale));'
  else:
   new=f' register f32* scale asm("$15")=&{global_name};\n asm("" : "+r"(scale) : "r"(receiver));'
  assert old in text;text=text.replace(old,new)
  sources[f'eight_hour_{address}_v8_receiver_global_{profile}.cpp']=text
for profile in range(8):
 text=(base/'eight_hour_002d49c0_v3_block_dependencies_1.cpp').read_text()
 text=text.replace('asm("" : "+f"(copied));','asm("" : "+f"(copied) : "r"(block));')
 text=text.replace(' block[0]=copied;',' *(f32*)(object+0x300)=copied;')
 if profile&1:
  text=text.replace(' object[0x30d]=0;',' object[0x30c]=0;').replace(' object[0x30c]=0;\n}', ' object[0x30d]=0;\n}')
 if profile&2:
  old=' register f32* scale asm("$15")=&D_00375af0;\n asm("" : "+r"(scale));'
  new=' register u32 high asm("$15");\n asm("lui %0,0x37" : "=r"(high) : "f"(copied),"r"(block));\n register f32* scale asm("$15")=(f32*)(high+0x5af0);\n asm("" : "+r"(scale));'
  assert old in text;text=text.replace(old,new)
  start=text.index(' block[3]=copied;');end=text.index(' object[0x30',start)
  chunk=text[start:end];stores=' block[3]=copied;\n block[1]=copied;\n block[2]=copied;\n'
  assert chunk.startswith(stores)
  text=text[:start]+chunk[len(stores):]+' asm("" : "+r"(block),"+f"(copied) : "r"(scale));\n'+stores+text[end:]
 if profile&4:
  text=text.replace(' object[0x305]=0;\n object[0x306]=0;\n object[0x307]=0;', ' object[0x307]=0;\n object[0x306]=0;\n object[0x305]=0;')
 sources[f'eight_hour_002d49c0_v8_float_block_flow_{profile}.cpp']=text
for name,text in sources.items():
 assert not (base/name).exists();(base/name).write_text(text)
(base/'extended-constructor-v8-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_extended_constructors_v8.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','extended-constructor-v8-variants.json'))
print('Prepared sixteen receiver and float-flow hypotheses.')
