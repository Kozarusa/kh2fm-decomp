"""Explore branch layout after matching scalar/VU register allocation."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
text = (base / 'eight_hour_0017d160_joined_pinned_barrier.cpp').read_text()
variants = []
for first in [None, 0, 1]:
    for second in [0, 1]:
        source = text
        if first is not None:
            source = source.replace('if(threshold<=dot)', f'if(__builtin_expect(threshold<=dot,{first}))')
        source = source.replace('if(dot<=threshold)', f'if(__builtin_expect(dot<=threshold,{second}))')
        variants.append((f'expect_{first}_{second}', source))
prefix = text[:text.index(' if(threshold<=dot)')]
second_setup = ''' asm volatile("" : : : "$15","memory");
 register const f32* upper asm("$15")=&D_0036c55c;
 asm("" : "+r"(upper));
 threshold=*upper;
 asm("" : "+f"(threshold));
'''
limit_setup = ''' register const f32* limit asm("$15")=&D_0036c560;
 asm("" : "+r"(limit));
'''
variants.append(('scoped_goto', prefix + ' if(threshold<=dot) {result=0.0f;goto finish;}\n {\n' + second_setup + ' if(dot<=threshold) {\n' + limit_setup + ' result=*limit;goto finish;\n }\n return func_002f8aa0(dot);\n }\n finish: return result;\n}\n'))
variants.append(('load_before_branch', prefix + ' if(threshold<=dot) result=0.0f;\n else {\n' + second_setup + ' s32 small=dot<=threshold;\n' + limit_setup + ' result=*limit;\n if(!small) return func_002f8aa0(dot);\n }\n return result;\n}\n'))
variants.append(('nested_result', prefix + ' if(threshold<=dot) result=0.0f;\n else {\n' + second_setup + ' if(!(dot<=threshold)) return func_002f8aa0(dot);\n' + limit_setup + ' result=*limit;\n }\n return result;\n}\n'))
names = []
for tag, source in variants:
    name = f'eight_hour_0017d160_v2_{tag}.cpp'
    path = base / name
    assert not path.exists()
    path.write_text(source)
    names.append(name)
(base / 'angle-v2-variants.json').write_text(json.dumps(names, indent=2) + '\n')
runner = (base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'angle-v2-variants.json'")
(base / 'probe_angle_v2.py').write_text(runner)
print(f'Prepared {len(names)} branch-layout variants.')
