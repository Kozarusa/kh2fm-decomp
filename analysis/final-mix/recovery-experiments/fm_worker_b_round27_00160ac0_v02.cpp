#include "../common/types.h"

/* 00160ac0 - v02. v01 was 76/76 with exactly two words transposed: GCC put
 * `addiu a3,a3,2528` in the jal delay slot and emitted `move a1,zero` earlier;
 * the target does the opposite. v02 routes the fourth argument through a named
 * temp so the constant is built before the zero move. */

extern "C" u32 func_00102788(u32, u32, u32, u32);
extern "C" u32 D_004f3b30;
extern "C" char func_00160a90;

void func_00160ac0(u32 param_1, u32 param_2)
{
  u32 iVar3 = 0x1609e0;
  u32 iVar1 = func_00102788(D_004f3b30, 0, param_2, iVar3);
  *(u32 *)(iVar1 + 4) = param_1;
  *(u32 *)(iVar1 + 48) = (u32)(long)&func_00160a90;
  return;
}
