from pathlib import Path
import json
base=Path(__file__).resolve().parent;names=[]
for address in ('002d96d8','002d9730'):
 text=(base/f'eight_hour_{address}_v5_word_store_dependency_0.cpp').read_text()
 old=' asm ("sw $0,3060(%2)" : "+r"(one),"=m"(object[0x2fd]) : "r"(object),"m"(*object));'
 assert old in text;text=text.replace(old,' object[0x2fd]=0;\n asm("" : "+r"(one) : "m"(object[0x2fd]),"m"(*object));')
 name=f'eight_hour_{address}_v6_cpp_word_store_dependency.cpp';assert not(base/name).exists();(base/name).write_text(text);names.append(name)
(base/'byte-float-constructor-v6-variants.json').write_text(json.dumps(names))
(base/'probe_byte_float_constructors_v6.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','byte-float-constructor-v6-variants.json'))
