#include "../common/types.h"

extern "C" s64 func_001bb4a0(void);
extern "C" u32 func_001bbcb0(void);

u8 func_001bbcc0(void)
{
  u8 uVar1;
  s32 iVar2;
  s64 lVar3;
  lVar3 = func_001bb4a0();
  uVar1 = 1;
  if (lVar3 != 0) {
    iVar2 = func_001bbcb0();
    uVar1 = *(u8 *)(*(u32 *)(iVar2 + 8) + 0xe);
  }
  return uVar1;
}
