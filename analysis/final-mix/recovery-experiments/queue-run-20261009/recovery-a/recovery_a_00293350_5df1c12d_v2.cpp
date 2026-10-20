#include "../common/types.h"
extern "C" u32 func_00103eb0(void);
extern "C" u32 func_00102818(u64,u64,u64,u64,s32);
extern "C" char func_002933b8;

void func_00293350(u32 param_1,u32 param_2,u32 param_3)

{
  int iVar1;
  
  iVar1 = func_00103eb0();
  iVar1 = func_00102818(*(u32 *)(iVar1 + 4),0,140000,(s32)(long)&func_002933b8,0x1000);
  *(u32 *)(iVar1 + 0xc) = param_3;
  asm volatile ("" ::: "memory");
  *(u32 *)(iVar1 + 4) = param_1;
  asm volatile ("" ::: "memory");
  *(u32 *)(iVar1 + 8) = param_2;
  return;
}
