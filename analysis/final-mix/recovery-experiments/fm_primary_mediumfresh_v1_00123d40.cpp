#include "../common/types.h"
// Provisional decompiler recovery; no exactness is assumed.
extern "C" u64 func_00124748(u64,u64);
typedef u64 code(u64,u64,u64);

void func_00123d40(u64 param_1,u64 param_2,u64 param_3)

{
  u64 uVar1;
  
  uVar1 = func_00124748(param_1,0);
  (**(code **)(*(int *)uVar1 + 0x10))(uVar1,param_2,param_3);
  return;
}

