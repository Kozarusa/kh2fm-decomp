"""Expand only the two complete original opcode families already independently proven."""
from pathlib import Path
import hashlib,json
base=Path(__file__).resolve().parent;rows=json.loads((base/'sdk-frame-wrapper-census.json').read_text())['pending'];names=[]
for row in rows:
 address=row['address'];control='002b6b84' if row['payloads'] else '002b7f84'
 suffix='v4_argument_constant_dependencies_1' if row['payloads'] else 'v3_frame_ABI_primitives_0'
 source=base/f'eight_hour_{control}_{suffix}.cpp';proof=json.loads(source.with_suffix('.verification.json').read_text());assert proof['source_sha256']==hashlib.sha256(source.read_bytes()).hexdigest();assert len(proof['rows'])==1 and proof['rows'][0]['exact_match']
 text=source.read_text().replace(f'func_{control}(',f'func_{address}(')
 if row['payloads']:
  assert 'addiu %0,$0,8' in text;text=text.replace('addiu %0,$0,8',f'addiu %0,$0,{row["operation"]}')
 else:
  assert 'func_002b6708(1,49)' in text;text=text.replace('func_002b6708(1,49)',f'func_002b6708(1,{row["operation"]})')
 text=text.replace(f'u64 func_{address}(',f'// Native frame setup and restoration are retained as ABI primitives.\nu64 func_{address}(')
 name=f'eight_hour_{address}_sdk_frame_family.cpp';assert not(base/name).exists();(base/name).write_text(text);names.append(name)
(base/'sdk-frame-family-variants.json').write_text(json.dumps(names))
(base/'probe_sdk_frame_family.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','sdk-frame-family-variants.json'))
print(f'Prepared {len(names)} complete SDK wrapper candidates; each still requires its own proof.')
