#include "../common/types.h"

/* 0014a138 - v02. v01 declared the global as 0x33b96c and measured lui 0x34, which
 * shows this compiler rounds rather than truncates here:
 * (0x33b96c + 0x8000) >> 16 == 0x34. Declaring 0x32b96c gives
 * (0x32b96c + 0x8000) >> 16 == 0x33 with the same low half 0xb96c, so the
 * lw offset is still -18068 and the effective address is still 0x32b96c. */

extern "C" u32 func_00102818(u32, u32, u32, u32, u32);
extern "C" u32 D_0032b96c;

void func_0014a138(u8 param_1)
{
  u32 iVar1 = func_00102818(D_0032b96c, 0, 300000, 0x14a0a0, 0x1000);
  *(u8 *)(iVar1 + 4) = param_1;
  return;
}
