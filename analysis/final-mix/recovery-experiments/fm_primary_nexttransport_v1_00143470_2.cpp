#include "../common/types.h"
// Provisional compiler proposal; complete-range proof is required.
extern "C" void func_001652c8(u32,u32,u32,u32,u32,u32,u32,u32);
extern "C" u32 D_00348804;

void func_00143470(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
                 u32 param_5,u32 param_6,u32 param_7)

{
  func_001652c8(D_00348804,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  asm volatile("");
  return;
}

