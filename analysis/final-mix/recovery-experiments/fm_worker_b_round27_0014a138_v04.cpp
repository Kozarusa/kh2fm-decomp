#include "../common/types.h"

/* 0014a138 - v04. Residual: the fourth argument's constant pair. The target
 * uses `lui a3,0x15` plus `addiu a3,a3,0xa0a0`, GCC uses `lui a3,0x14` plus
 * `ori a3,a3,0xa0a0`; both denote 0x14a0a0, so this is the compiler's
 * address-mode versus integer-mode constant form. v04 types the fourth
 * parameter as a plain signed int. */

extern "C" u32 func_00102818(u32, u32, u32, int, u32);
extern "C" u32 D_0032b96c;

void func_0014a138(u8 param_1)
{
  u32 iVar1 = func_00102818(D_0032b96c, 0, 300000, 0x14a0a0, 0x1000);
  *(u8 *)(iVar1 + 4) = param_1;
  return;
}
