#include "../common/types.h"

extern "C" u64 func_001bb4a0(void);
extern "C" u64 func_001bbcb0(void);

u32 func_001bbf00(void)
{
  u64 lVar2;
  u32 uVar3;
  volatile u16 *puVar1;
  lVar2 = func_001bb4a0();
  uVar3 = 0;
  if (lVar2 != 0) {
    lVar2 = func_001bbcb0();
    puVar1 = (volatile u16 *)(lVar2 + 12);
    uVar3 = (*puVar1 >> 12) & 1;
  }
  return uVar3;
}
