#include "../common/types.h"

/* 00160ac0 - v05. The only residual is the fourth argument's constant pair:
 * the target materialises it with `lui a3,0x16` plus `addiu a3,a3,0x9e0`,
 * while GCC uses `ori a3,a3,0x9e0` in the jal delay slot. Both encodings carry
 * the same value, so this is a form difference, not a value difference. v05
 * types the callee's fourth parameter as a plain signed int so the argument is
 * expanded in integer mode rather than as a pointer-mode address constant. */

extern "C" u32 func_00102788(u32, u32, u32, int);
extern "C" u32 D_004f3b30;
extern "C" char func_00160a90;

void func_00160ac0(u32 param_1, u32 param_2)
{
  u32 iVar1 = func_00102788(D_004f3b30, 0, param_2, 0x1609e0);
  *(u32 *)(iVar1 + 4) = param_1;
  *(u32 *)(iVar1 + 48) = (u32)(long)&func_00160a90;
  return;
}
