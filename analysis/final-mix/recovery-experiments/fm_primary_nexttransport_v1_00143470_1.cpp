#include "../common/types.h"
// Provisional compiler proposal; complete-range proof is required.
extern "C" void func_001652c8(u32,u64,u64,u64,u64,u64,u64,u64);
extern "C" u32 D_00348804;

void func_00143470(u64 param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5,u64 param_6,u64 param_7)

{
  func_001652c8(D_00348804,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  asm volatile("");
  return;
}

