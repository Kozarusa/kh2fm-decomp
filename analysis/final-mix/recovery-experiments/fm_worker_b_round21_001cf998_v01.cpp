#include "../common/types.h"

extern "C" u64 func_001bb4a0(void);
extern "C" s32 func_001d87b8(u32);

u32 func_001cf998(void)
{
  s32 iVar1;
  u64 uVar1;
  uVar1 = func_001bb4a0();
  iVar1 = 0;
  if (uVar1 != 0) { iVar1 = func_001d87b8(1); }
  return (u32)(iVar1 <= 0);
}
