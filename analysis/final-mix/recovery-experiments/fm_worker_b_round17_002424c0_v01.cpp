#include "../common/types.h"

extern "C" u32 func_001058e8(void);

u32 func_002424c0(s32 param_1)
{
  u32 uVar1;
  u32 uVar2;
  uVar1 = func_001058e8();
  uVar2 = *(u32 *)(uVar1 + 0x2440);
  uVar2 = uVar2 + param_1;
  uVar1 = 999999;
  return (uVar1 < uVar2) ^ 1;
}
