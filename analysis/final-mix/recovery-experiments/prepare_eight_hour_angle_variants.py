"""Prepare isolated scalar-return scheduling variants; never register them."""
from pathlib import Path
import json

ex = Path(__file__).resolve().parent
out = ex / 'eight-hour-20261011'
out.mkdir(exist_ok=True)
original = ex / 'queue-run-20261009/primary/fm_queue_primary_0017d160_2561ed92_angle.cpp'
base = original.read_text()
prefix = base[:base.index(' register const f32* lower')]
variants = []
for shape in ['early', 'joined', 'goto']:
    for pinned in [False, True]:
        for barrier in [False, True]:
            name = f'eight_hour_0017d160_{shape}_' + ('pinned' if pinned else 'plain') + ('_barrier' if barrier else '')
            qualify = 'register f32 threshold asm("$f0")' if pinned else 'f32 threshold'
            first = ' register const f32* lower asm("$15")=&D_0036c558;\n asm("" : "+r"(lower));\n'
            first += f' {qualify}=*lower;\n'
            if pinned:
                first += ' asm("" : "+f"(threshold));\n'
            second = ' register const f32* upper asm("$15")=&D_0036c55c;\n asm("" : "+r"(upper));\n threshold=*upper;\n'
            if barrier:
                second = ' asm volatile("" : : : "$15","memory");\n' + second
            if pinned:
                second += ' asm("" : "+f"(threshold));\n'
            third = ' register const f32* limit asm("$15")=&D_0036c560;\n asm("" : "+r"(limit));\n'
            if shape == 'early':
                body = first + ' if(threshold<=dot) return 0.0f;\n' + second
                body += ' if(dot<=threshold) {\n' + third + ' return *limit;\n }\n return func_002f8aa0(dot);\n}\n'
            elif shape == 'joined':
                body = ' register f32 result asm("$f0");\n' + first
                body += ' if(threshold<=dot) result=0.0f;\n else {\n' + second
                body += ' if(dot<=threshold) {\n' + third + ' result=*limit;\n } else return func_002f8aa0(dot);\n }\n return result;\n}\n'
            else:
                body = ' register f32 result asm("$f0");\n' + first
                body += ' if(threshold<=dot) {result=0.0f;goto finish;}\n' + second
                body += ' if(dot<=threshold) {\n' + third + ' result=*limit;goto finish;\n }\n return func_002f8aa0(dot);\n finish: return result;\n}\n'
            path = out / (name + '.cpp')
            assert not path.exists()
            path.write_text(prefix + body)
            variants.append(path.name)
(out / 'angle-variants.json').write_text(json.dumps(variants, indent=2) + '\n')
print(f'Prepared {len(variants)} isolated angle variants. Ordered comparisons retained.')
