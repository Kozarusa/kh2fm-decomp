#include "../common/types.h"

/* 0014a138 - v03. The only residual in v02 is how the fourth argument's constant
 * is formed. v02 (integer-typed) measured `lui a3,0x14` + `ori a3,a3,0xa0a0`;
 * the target uses `lui a3,0x15` + `addiu a3,a3,-24416`. Those are the two GCC
 * constant paths: the truncating (integer) path and the rounding (address) path.
 * Ghidra's signature is `undefined`, so the original argument may well have been
 * a pointer. v03 declares the fourth parameter as a pointer and passes
 * (void *)0x14a0a0, which should route it through the address path. The third
 * argument stays an integer, which is why its 0x93e0 keeps the `ori` form. */

extern "C" u32 func_00102818(u32, u32, u32, void *, u32);
extern "C" u32 D_0032b96c;

void func_0014a138(u8 param_1)
{
  u32 iVar1 = func_00102818(D_0032b96c, 0, 300000, (void *)0x14a0a0, 0x1000);
  *(u8 *)(iVar1 + 4) = param_1;
  return;
}
