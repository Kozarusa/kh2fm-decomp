#include "../common/types.h"

/* 00160ac0 - v04. Same hypothesis as 0014a138 v03: the fourth argument's
 * constant 0x1609e0 is built with addiu in the target and with ori when it is
 * declared as an integer. Declaring that parameter as a pointer selects the
 * rounding address path (lui 0x16 + addiu 0x9e0), which is what the target has. */

extern "C" u32 func_00102788(u32, u32, u32, void *);
extern "C" u32 D_004f3b30;
extern "C" char func_00160a90;

void func_00160ac0(u32 param_1, u32 param_2)
{
  u32 iVar1 = func_00102788(D_004f3b30, 0, param_2, (void *)0x1609e0);
  *(u32 *)(iVar1 + 4) = param_1;
  *(u32 *)(iVar1 + 48) = (u32)(long)&func_00160a90;
  return;
}
