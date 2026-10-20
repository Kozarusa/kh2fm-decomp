#include "../common/types.h"
// Provisional compiler proposal; complete-range proof is required.
extern "C" u64 func_0013b5d0(u32,u64,u64,u32,u32,u32,u32,u32,u32);
extern "C" void func_00139570(u64);
extern "C" u32 D_0036ad4c;

void func_0013c820(u64 param_1,u64 param_2)

{
  u64 uVar1;
  
  uVar1 = func_0013b5d0(D_0036ad4c,param_1,param_2,2,0,0,0,0,0);
  func_00139570(uVar1);
  return;
}

