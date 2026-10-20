#include "../common/types.h"

extern "C" u64 func_00242b58(u32);

u32 func_001585a0(u32 param_1)
{
  u32 uVar1;
  u32 uVar2;
  uVar1 = *(u32 *)param_1;
  uVar2 = uVar1 & 1;
  uVar2 = func_00242b58(uVar2);
  uVar1 = (uVar2 != 0);
  return (uVar1 != 0) ? uVar2 : (u32)(uVar2 == 0);
}
