from pathlib import Path
import json
base=Path(__file__).resolve().parent
sources={}
for address in ('00185b00','00185b70'):
 for profile in range(8):
  text=(base/f'eight_hour_{address}_v8_receiver_global_2.cpp').read_text()
  start=text.index(' register u32 table');end=text.index(' register u32* receiver',start)
  prefix=' register u32 table asm("$15")=(u32)&D_0034ed78;\n register u32 flags asm("$14")=object[0x162];\n asm("" : "+r"(table),"+r"(flags));\n'
  stores=' object[700]=0;\n *object=table;\n' if not profile&1 else ' *object=table;\n object[700]=0;\n'
  prefix+=stores
  if profile&2:
   qualifier='volatile ' if profile&4 else ''
   prefix+=f' asm {qualifier}("ori %0,%0,0x10" : "+r"(flags) : "m"(*object),"m"(object[700]));\n object[0x162]=flags;\n'
  else:
   deps='"m"(*object),"m"(object[700])' if profile&4 else '"m"(*object)'
   prefix+=f' asm("" : "+r"(flags) : {deps});\n object[0x162]=flags|0x10;\n'
  text=text[:start]+prefix+text[end:]
  sources[f'eight_hour_{address}_v9_flag_dependencies_{profile}.cpp']=text
for name,text in sources.items():
 assert not (base/name).exists();(base/name).write_text(text)
(base/'extended-constructor-v9-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_extended_constructors_v9.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','extended-constructor-v9-variants.json'))
print('Prepared sixteen field dependency probes.')
