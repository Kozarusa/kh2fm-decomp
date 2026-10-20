#include "../common/types.h"

/* 0014a138 - v01
 * lui t7,0x33 ; lw a0,-18068(t7) => effective address 0x330000-18068 = 0x32b96c.
 * The low half is unchanged by the one-page difference, so the symbol must be
 * declared as 0x33b96c to reproduce the target's truncating lui (round-6 rule). */

extern "C" u32 func_00102818(u32, u32, u32, u32, u32);
extern "C" u32 D_0033b96c;

void func_0014a138(u8 param_1)
{
  u32 iVar1 = func_00102818(D_0033b96c, 0, 300000, 0x14a0a0, 0x1000);
  *(u8 *)(iVar1 + 4) = param_1;
  return;
}
