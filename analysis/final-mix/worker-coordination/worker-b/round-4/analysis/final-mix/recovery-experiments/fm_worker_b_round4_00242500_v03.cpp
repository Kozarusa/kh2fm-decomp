#include "../common/types.h"

extern "C" u32 func_002424c0(...);
extern "C" u32 func_001058e8(...);

u32 func_00242500(s32 param_1)
{
  s32 lVar2;
  u32 uVar1;
  lVar2 = func_002424c0();
  if (lVar2 != 0) {
    uVar1 = func_001058e8();
    param_1 = *(int *)(uVar1 + 0x2440) + param_1;
  }
  else {
    param_1 = 999999;
  }
  uVar1 = func_001058e8();
  *(int *)(uVar1 + 0x2440) = param_1;
  return *(int *)(uVar1 + 0x2440);
}
