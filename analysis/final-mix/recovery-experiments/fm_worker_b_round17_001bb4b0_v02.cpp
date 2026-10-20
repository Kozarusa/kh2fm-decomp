#include "../common/types.h"

asm(".globl DAT_001d59320
	DAT_001d59320 = 0x1d59320
");
extern "C" u32 DAT_001d59320;
extern "C" u32 func_001bb4a0(void);

u32 func_001bb4b0(void)
{
  u32 uVar1;
  u32 uVar3;
  uVar1 = func_001bb4a0();
  uVar3 = 0;
  if (uVar1 != 0) {
    uVar3 = (*(u32 *)(DAT_001d59320 + 4) & 4) == 0;
  }
  return uVar3;
}
