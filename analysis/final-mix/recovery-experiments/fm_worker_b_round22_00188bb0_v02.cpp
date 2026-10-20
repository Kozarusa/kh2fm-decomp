#include "../common/types.h"

extern "C" s32 *func_001b6fb0(u32,u32);
extern "C" u32 DAT_00332210;
asm(".globl DAT_00332210
	DAT_00332210 = 0x32f210
");

s32 func_00188bb0(u8 *param_1, u32 param_2)
{
  s32 *piVar1;
  s32 iVar2;
  iVar2 = 0;
  if (param_1[0xf] < 99) {
    piVar1 = func_001b6fb0(param_2, param_1[0xf]);
    iVar2 = *piVar1 - (s32)DAT_00332210;
  }
  return iVar2;
}
