"""Generate typed object forwarding only for the validated complete native family."""
from pathlib import Path
import json
import subprocess
import sys
base = Path(__file__).resolve().parent
rows = json.loads((base / 'deleting-wrapper-census.json').read_text())
leases = json.loads((base / 'deleting-control-leases.json').read_text())
controls = {row['address'] for row in leases}
helper = base.parents[4] / 'Public/tools/kh2-audit/recovery_queue.py'
names = []
for row in rows:
    if row['accepted'] or row['state'] != ['ready','general'] or row['address'] in controls:
        continue
    address = row['address']
    result = subprocess.run([sys.executable,str(helper),'claim','--worker','eight-hour-primary','--count','1','--address',address],capture_output=True,text=True)
    with (base / f'deleting-family-claim-{address}.log').open('x') as stream:
        stream.write(result.stdout+result.stderr)
    assert result.returncode == 0, result.stdout+result.stderr
    claimed = json.loads(result.stdout)['leases']
    assert len(claimed)==1
    leases.extend(claimed)
    name = f'eight_hour_{address}_deleting_family.cpp'
    text = f'#include "../common/types.h"\n\n// The original range passes the same object to both helpers.\n// C++ class identities and helper semantics remain provisional.\nextern "C" u8 D_{row["vtable"]};\nextern "C" void func_{row["first_helper"]}(u32*);\nextern "C" void func_{row["final_helper"]}(u32*);\n\nvoid func_{address}(u32* object)\n{{\n *object=(u32)&D_{row["vtable"]};\n func_{row["first_helper"]}(object);\n func_{row["final_helper"]}(object);\n}}\n'
    (base/name).write_text(text)
    names.append(name)
with (base/'deleting-family-leases.json').open('x') as stream:
    json.dump(leases,stream,indent=2)
(base/'deleting-family-variants.json').write_text(json.dumps(names))
(base/'probe_deleting_family.py').write_text((base/'probe_quad_copy.py').read_text().replace('quad-copy-variants.json','deleting-family-variants.json'))
print(f'Prepared and claimed {len(names)} further candidates; {len(controls)} controls remain leased.')
