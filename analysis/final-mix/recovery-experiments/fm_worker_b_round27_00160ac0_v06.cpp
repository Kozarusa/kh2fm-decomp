#include "../common/types.h"

/* 00160ac0 - v06. As v05 but the fourth argument is passed as a variable
 * declared `int`, so the literal cannot stay a bare address-mode constant. */

extern "C" u32 func_00102788(u32, u32, u32, int);
extern "C" u32 D_004f3b30;
extern "C" char func_00160a90;

void func_00160ac0(u32 param_1, u32 param_2)
{
  int iVar3 = 0x1609e0;
  u32 iVar1 = func_00102788(D_004f3b30, 0, param_2, iVar3);
  *(u32 *)(iVar1 + 4) = param_1;
  *(u32 *)(iVar1 + 48) = (u32)(long)&func_00160a90;
  return;
}
