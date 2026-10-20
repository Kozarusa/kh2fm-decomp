#include "../common/types.h"
// Provisional decompiler recovery; no exactness is assumed.
extern "C" u32 func_00124748(u32,u32);
typedef void code(u32,u64,u64);


void func_00123d40(u32 param_1,u64 param_2,u64 param_3)



{

  register u32 uVar1 asm("$2");

  

  uVar1 = func_00124748(param_1,0);

  asm volatile("" : "+r"(uVar1));
  (**(code **)(*(int *)uVar1 + 0x10))(uVar1,param_2,param_3);

  return;

}



