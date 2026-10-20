#include "../common/types.h"

extern "C" u64 func_002424c0(...);
extern "C" s32 func_001058e8(...);

u32 func_00242500(s32 param_1)
{
  s64 lVar2;
  s32 iVar1;
  lVar2 = func_002424c0();
  if (lVar2 == 0) {
    iVar1 = func_001058e8();
    param_1 = 999999;
  }
  else {
    iVar1 = func_001058e8();
    param_1 = *(int *)(iVar1 + 0x2440) + param_1;
  }
  *(int *)(iVar1 + 0x2440) = param_1;
  iVar1 = func_001058e8();
  return *(u32 *)(iVar1 + 0x2440);
}
