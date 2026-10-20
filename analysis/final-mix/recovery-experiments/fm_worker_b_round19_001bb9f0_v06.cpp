#include "../common/types.h"

asm(".globl DAT_01d59320
	DAT_01d59320 = 0x1d59320
");
extern "C" u32 *DAT_01d59320;
extern "C" u64 func_001bb4a0(void);

u16 func_001bb9f0(void)
{
  u16 uVar3;
  uVar3 = 0;
  if (func_001bb4a0() != 0) {
    uVar3 = (*(u16 *)(*(u32 *)((u32 *)DAT_01d59320)[2] + 4) >> 9) & 1;
  }
  return uVar3;
}
