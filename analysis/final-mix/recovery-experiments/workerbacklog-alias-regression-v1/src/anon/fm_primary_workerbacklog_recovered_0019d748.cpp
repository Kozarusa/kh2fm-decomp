#include "../common/types.h"

extern "C" u64 func_00181858(void);

u32 func_0019d748(u32 param_1)
{
  u64 lVar2;
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  uVar1 = 0;
  lVar2 = func_00181858();
  if (lVar2 != 0) {
    uVar2 = *(u32 *)((u8 *)param_1 + 32);
    uVar3 = uVar2 & 1;
    uVar1 = (uVar3 != 0) ? 1 : 0;
  }
  return uVar1;
}
