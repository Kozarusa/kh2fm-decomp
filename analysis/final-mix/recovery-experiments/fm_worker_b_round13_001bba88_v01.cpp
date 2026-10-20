#include "../common/types.h"

asm(".globl DAT_01d59320
	DAT_01d59320 = 0x1d59320
");

extern "C" u32 DAT_01d59320;

extern "C" u64 func_001bb4a0(void);
extern "C" u64 func_001bba30(u32);

u64 func_001bba88(void)
{
  u64 lVar1;
  u64 uVar2;
  lVar1 = func_001bb4a0();
  if (lVar1 == 0) {
    uVar2 = 0;
  } else {
    uVar2 = func_001bba30(DAT_01d59320);
  }
  return uVar2;
}
