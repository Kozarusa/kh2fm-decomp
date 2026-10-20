#include "../common/types.h"

extern "C" u64 func_001bb4a0(void);
extern "C" u64 func_001bbcb0(void);

u16 func_001bc050(void)
{
  u64 lVar2;
  u16 uVar3;
  lVar2 = func_001bb4a0();
  uVar3 = 0;
  if (lVar2 != 0) {
    uVar3 = (*(u16 *)(*(u32 *)(func_001bbcb0() + 8) + 4) >> 14) & 1;
  }
  return uVar3;
}
