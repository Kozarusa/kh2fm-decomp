#include "../common/types.h"

extern "C" u64 func_00181858(void);
u32 func_0019d748(u32 param_1)
{
  u64 lVar2;
  u32 uVar1;
  uVar1 = 0;
  lVar2 = func_00181858();
  if (lVar2 != 0) {
    uVar1 = (u32)((*((u32 *)param_1) + 8) & 1) != 0;
  }
  return uVar1;
}
