from pathlib import Path
import json
ex=Path(__file__).resolve().parent
names=[]
for address in ['001dc488','001de948','001e0128','001e0188']:
 proof=json.loads((ex/f'fm_primary_epiloguefamily_v1_{address}_1.verification.json').read_text())['rows'][0]
 words=[int.from_bytes(bytes.fromhex(proof['target_hex'])[i:i+4],'little') for i in range(0,48,4)]
 high=words[3]&65535; low=words[4]&65535
 low_signed=low if low<32768 else low-65536
 global_address=((high<<16)+low_signed)&0xffffffff
 for variant in range(1,5):
  name=f'fm_primary_callbackaddress_v1_{address}_{variant}.cpp'
  head=f'#include "../common/types.h"\nextern "C" u32 D_{global_address:08x};\ntypedef void (*code)(u32,u32,u32);\n'
  if variant==1:
   body=f'  (*(code *)(*(u32 *)D_{global_address:08x}))(D_{global_address:08x},param_1,0);\n  asm volatile("");'
  else:
   object_reg='4' if variant==2 else '14'
   body=f'''  register u32 high asm("$15");
  asm volatile("lui %0,%1" : "=r"(high) : "i"({high}));
  register u32 object asm("${object_reg}");
  asm volatile("lw %0,%1(%2)" : "=r"(object) : "i"({low_signed}), "r"(high) : "memory");
  register u32 table asm("$15")=*(u32 *)object;
  register code callback asm("$2")=*(code *)table;
  asm volatile("" : "+r"(table), "+r"(callback));
  callback(object,param_1,0);
  asm volatile("");'''
   if variant==4:
    body=body.replace('asm("$14")','asm("$4")').replace('asm volatile("" : "+r"(table), "+r"(callback));','asm volatile("" : "+r"(callback));')
  (ex/name).write_text(head+f'void func_{address}(u32 param_1)\n{{\n'+body+'\n}\n',encoding='utf-8')
  names.append(name)
runner=(ex/'probe_epiloguefamily_v1.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
runner=runner[:start]+'names='+repr(names)+runner[end:]
(ex/'probe_callbackaddress_v1.py').write_text(runner,encoding='utf-8')
print(names)
