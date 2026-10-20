#include "../common/types.h"

extern "C" u64 func_001bb4a0(void);
extern "C" u64 func_001bbcb0(void);

u32 001bbf00(void)
{
  u64 lVar2;
  u32 uVar3;
  u32 *puVar1;
  lVar2 = func_001bb4a0();
  uVar3 = 0;
  if (lVar2 != 0) {
    puVar1 = (u32 *)(lVar2 + 8);
    uVar3 = (*(u16 *)(puVar1 + 1) >> 12) & 1;
  }
  return uVar3;
}
