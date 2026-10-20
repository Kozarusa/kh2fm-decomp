from pathlib import Path
import json
import subprocess
import sys
base=Path(__file__).resolve().parent
helper=base.parents[4]/'Public/tools/kh2-audit/recovery_queue.py'
leases=[]
names=[]
for address,vtable,callee,global_address,nested in (('0031e110','0034c720','00160268','0034c738',False),('0031c9a8','00347e40','0031cd50','00347f80',True),('0031ca20','00347e40','0031cd50','00347f80',True)):
    result=subprocess.run([sys.executable,str(helper),'claim','--worker','eight-hour-primary','--count','1','--address',address],capture_output=True,text=True)
    assert result.returncode==0,result.stdout+result.stderr
    claimed=json.loads(result.stdout)['leases']
    assert len(claimed)==1
    leases.extend(claimed)
    for volatile in (0,1):
        name=f'eight_hour_{address}_virtual_cleanup_{volatile}.cpp'
        qualifier='volatile ' if volatile else ''
        text=f'#include "../common/types.h"\ntypedef void (*Callback)(u32*,u32*);\nextern "C" u8 D_{vtable};\nextern "C" u32* D_{global_address};\nextern "C" void func_{callee}(u32*);\nvoid func_{address}(u32* object)\n{{\n *({qualifier}u32*)object=(u32)&D_{vtable};\n func_{callee}(object);\n'
        text+=f' u32* receiver=(u32*)D_{global_address}[5];\n' if nested else f' u32* receiver=D_{global_address};\n'
        text+=' ((Callback*)receiver[0])[1](receiver,object);\n}\n'
        (base/name).write_text(text)
        names.append(name)
with (base/'virtual-cleanup-leases.json').open('x') as stream:
    json.dump(leases,stream,indent=2)
(base/'virtual-cleanup-variants.json').write_text(json.dumps(names))
(base/'probe_virtual_cleanup.py').write_text((base/'probe_quad_copy.py').read_text().replace('quad-copy-variants.json','virtual-cleanup-variants.json'))
print('Claimed three virtual-cleanup candidates.')
