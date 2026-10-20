#include "../common/types.h"

extern "C" u64 func_001d7f10(void);
extern "C" u32 DAT_003528f8;
asm(".globl DAT_003528f8
	DAT_003528f8 = 0x3528f8
");

s32 func_001d7ec8(u32 param_1)
{
  u64 uVar1;
  u32 uVar2;
  s32 iVar1;
  iVar1 = 0;
  uVar2 = param_1 * 4;
  uVar1 = func_001d7f10();
  if (uVar1 != 0) {
    iVar1 = *(s32 *)((u8 *)DAT_003528f8 + uVar2 + 8);
  }
  return iVar1;
}
