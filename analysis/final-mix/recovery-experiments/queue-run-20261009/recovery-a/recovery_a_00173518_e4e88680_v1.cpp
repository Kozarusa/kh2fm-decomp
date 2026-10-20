#include "../common/types.h"
extern "C" u32 func_00102c18(u64,u64,u64);
extern "C" char func_001734b0;

void func_00173518(u32 *param_1)

{
  int iVar1;
  
  iVar1 = func_00102c18(1,0x36b2,(u32)(long)&func_001734b0);
  *(u32 *)(iVar1 + 4) = 0;
  *(u32 *)(iVar1 + 8) = *param_1;
  return;
}
