from pathlib import Path
ex=Path(__file__).resolve().parent
s=(ex/'register_callbackaddress.py').read_text(encoding='utf-8')
s=s.replace('callbackaddress','callbackreturn').replace('floatiterator','callbackaddress')
s=s.replace("['001dc488','001de948','001e0128','001e0188']","['001050d8','0016c7a0','0016fac8','00288be8','0028cc08']")
s=s.replace(".replace('callbackaddress','callbackreturn')",".replace('callbackaddress','callbackreturn')")
(ex/'register_callbackreturn.py').write_text(s,encoding='utf-8')
