#include "../common/types.h"

extern "C" u64 func_001bb4a0(void);
extern "C" s32 func_001d87b8(u32);

u32 func_001cf998(void)
{
  u64 uVar1;
  s32 iVar1;
  u32 uVar2;
  u32 uVar3;
  uVar2 = 0;
  uVar3 = 0;
  uVar1 = func_001bb4a0();
  if (uVar1 != 0) {
    iVar1 = func_001d87b8(1);
    if (iVar1 > 0) { uVar3 = 1; }
  }
  asm volatile ("");
  uVar2 = uVar3;
  return uVar2;
}
