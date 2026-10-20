#include "../common/types.h"

extern "C" u32 func_00192048(u32);
extern "C" void func_002595e8(u32,u32);
extern "C" char func_00373970;

u32 func_00271828(u32 param_1, u32 param_2)
{
  u32 *puVar1;
  register u32 uVar1 asm("$2");
  puVar1 = (u32 *)(long)&func_00373970;
  uVar1 = func_00192048(*(u32 *)((u8 *)puVar1 + param_1 * 4));
  register u32 argument asm("$4")=param_2; asm("daddu %0,%1,$0" : "=r"(argument) : "r"(param_2),"r"(uVar1)); func_002595e8(argument, uVar1);
  return param_2;
}
