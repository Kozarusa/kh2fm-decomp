#include "../common/types.h"

/* 00160ac0 - v03. Same goal as v02 from the other side: make the second
 * argument an ordinary value so that its `move a1,zero` is generated last and
 * becomes the delay-slot filler. */

extern "C" u32 func_00102788(u32, u32, u32, u32);
extern "C" u32 D_004f3b30;
extern "C" char func_00160a90;

void func_00160ac0(u32 param_1, u32 param_2)
{
  u32 iVar3 = 0;
  u32 iVar1 = func_00102788(D_004f3b30, iVar3, param_2, 0x1609e0);
  *(u32 *)(iVar1 + 4) = param_1;
  *(u32 *)(iVar1 + 48) = (u32)(long)&func_00160a90;
  return;
}
