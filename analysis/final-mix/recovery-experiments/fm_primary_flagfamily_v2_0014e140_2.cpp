#include "../common/types.h"
// Provisional recovery; complete-range proof is required.
extern "C" char D_00349f00;
extern "C" u32 func_0014e648(u32);
extern "C" void func_0014dd60(u32,u8,u8,u8);

void func_0014e140(u32 param_1,u8 param_2,u8 param_3)

{
  u32 uVar1;
  
  register u32 first asm("$16")=param_1&255;
  asm("" : "+r"(first));
  uVar1 = func_0014e648((u32)&D_00349f00);
  func_0014dd60(uVar1,first,param_2,param_3);
  return;
}

