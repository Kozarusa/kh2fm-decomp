from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
sources={
'001c8a90':[
'''  u32 *base=&D_01d49960;
  *base=0; base[1]=0; D_01d49968=0;''',
'''  volatile u32 *base=&D_01d49960;
  *base=0; base[1]=0; D_01d49968=0;''',
'''  u32 *base=&D_01d49960;
  *base=0; base[1]=0; *(volatile u32 *)&D_01d49968=0;'''],
'00305e20':[
'''  s32 *pointer=func_00316d08();
  register s32 value asm("$3")=5;
  asm volatile("" : "+r"(value));
  *pointer=value;
  return -1;''',
'''  register s32 *pointer asm("$2")=func_00316d08();
  register s32 value asm("$3");
  asm volatile("addiu %0,$0,5" : "=r"(value));
  *pointer=value;
  return -1;'''],
'0030ec28':[
'''  u32 result=func_00305a30(4);
  register u32 mask asm("$3")=0x10000;
  asm volatile("" : "+r"(mask));
  return (result&mask)!=0;''',
'''  u32 result=func_00305a30(4);
  register u32 mask asm("$3");
  asm volatile("lui %0,1" : "=r"(mask));
  return (result&mask)!=0;''']}
headers={
'001c8a90':'extern "C" u32 D_01d49960;\nextern "C" u32 D_01d49968;\nvoid func_001c8a90(void)',
'00305e20':'extern "C" s32 *func_00316d08(void);\ns32 func_00305e20(void)',
'0030ec28':'extern "C" u32 func_00305a30(u32);\nbool func_0030ec28(void)'}
for address,variants in sources.items():
 for number,body in enumerate(variants,1):
  name=f'fm_primary_shortglobals_v1_{address}_{number}.cpp'
  (ex/name).write_text('#include "../common/types.h"\n'+headers[address]+'\n{\n'+body+'\n}\n',encoding='utf-8')
  names.append(name)
runner=(ex/'probe_callbackreturn_v2.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_shortglobals_v1.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
