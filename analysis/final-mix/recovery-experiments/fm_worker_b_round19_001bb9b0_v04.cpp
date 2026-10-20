#include "../common/types.h"

asm(".globl DAT_01d59320
	DAT_01d59320 = 0x1d59320
");
extern "C" u32 *DAT_01d59320;
extern "C" u64 func_001bb4a0(void);

u32 func_001bb9b0(void)
{
  u32 uVar3;
  volatile u16 *puVar1;
  uVar3 = 0;
  if (func_001bb4a0() != 0) {
    puVar1 = (volatile u16 *)((u8 *)((u32 *)DAT_01d59320)[2] + 4);
    uVar3 = (*puVar1 >> 4) & 1;
  }
  return uVar3;
}
