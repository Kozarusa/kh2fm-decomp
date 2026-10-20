#include "../common/types.h"

extern "C" u32 func_001bb4a0(void);
extern "C" u32 func_001bbcb0(void);

u64 func_001bbcc0(void)
{
  u32 uVar1;
  u32 iVar2;
  uVar1 = func_001bb4a0();
  if (uVar1 != 0) {
    iVar2 = func_001bbcb0();
    uVar1 = *(u8 *)(*(u32 *)(iVar2 + 8) + 0xe);
  } else {
    uVar1 = 1;
  }
  return uVar1;
}
