#include "../common/types.h"

asm(".globl DAT_01d59320
	DAT_01d59320 = 0x1d59320
");
extern "C" u32 *DAT_01d59320;
extern "C" u64 func_001bb4a0(void);

u16 func_001bbf00(void)
{
  u16 uVar2;
  u16 uVar3;
  u32 *puVar1;
  uVar3 = 0;
  if (func_001bb4a0() != 0) {
    puVar1 = (u32 *)((u32 *)DAT_01d59320)[2];
    uVar2 = *(u16 *)((u8 *)puVar1 + 4);
    asm volatile ("" : "+r"(uVar2));
    uVar3 = (uVar2 >> 4) & 1;
  }
  return uVar3;
}
