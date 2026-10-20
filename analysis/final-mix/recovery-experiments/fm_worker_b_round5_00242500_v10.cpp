#include "../common/types.h"

extern "C" u32 func_002424c0(...);
extern "C" u32 func_001058e8(...);

u32 func_00242500(s32 param_1)
{
  s32 iVar1;
  u32 uVar1;
  u32 uVar2;
  uVar2 = func_002424c0();
  if (uVar2 == 0) {
    uVar1 = func_001058e8();
    iVar1 = 999999;
  }
  else {
    uVar1 = func_001058e8();
    iVar1 = *(int *)(uVar1 + 0x2440) + param_1;
  }
  *(int *)(uVar1 + 0x2440) = iVar1;
  uVar1 = func_001058e8();
  return *(int *)(uVar1 + 0x2440);
}
