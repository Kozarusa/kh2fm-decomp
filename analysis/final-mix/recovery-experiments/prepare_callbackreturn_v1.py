from pathlib import Path
import json
ex=Path(__file__).resolve().parent
names=[]
for address in ['001050d8','0016c7a0','0016fac8','00288be8','0028cc08']:
 old=next(ex.glob(f'fm_worker_b_round*_{address}_v0*.verification.json'))
 proof=json.loads(old.read_text())['rows'][0]
 words=[int.from_bytes(bytes.fromhex(proof['target_hex'])[i:i+4],'little') for i in range(0,52,4)]
 high=words[3]&65535;low=words[5]&65535
 low_signed=low if low<32768 else low-65536
 global_address=(high<<16)+low_signed
 for variant in range(1,4):
  name=f'fm_primary_callbackreturn_v1_{address}_{variant}.cpp'
  header=f'#include "../common/types.h"\nextern "C" u32 D_{global_address:08x};\ntypedef void (*code)(u32,u32,u32);\n'
  body=f'''  register u32 object asm("$4")=D_{global_address:08x};
  register u32 table asm("$15")=*(u32 *)object;
  register code callback asm("$2")=*(code *)table;
  asm volatile("" : "+r"(table), "+r"(callback));
  callback(object,param_1,(u32)__builtin_return_address(0));
  asm volatile("");'''
  if variant==2:
   body=body.replace('asm volatile("" : "+r"(table), "+r"(callback));','asm volatile("" : "+r"(callback));')
  if variant==3:
   body=body.replace(f'register u32 object asm("$4")=D_{global_address:08x};',f'register u32 high asm("$15");\n  asm volatile("lui %0,%1" : "=r"(high) : "i"({high}));\n  register u32 object asm("$4");\n  asm volatile("lw %0,%1(%2)" : "=r"(object) : "i"({low_signed}), "r"(high) : "memory");')
  (ex/name).write_text(header+f'void func_{address}(u32 param_1)\n{{\n'+body+'\n}\n',encoding='utf-8')
  names.append(name)
runner=(ex/'probe_callbackaddress_v1.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_callbackreturn_v1.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
print(names)
