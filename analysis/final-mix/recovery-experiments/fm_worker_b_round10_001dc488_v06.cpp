#include "../common/types.h"

asm(".globl DAT_01d6bb00
	DAT_01d6bb00 = 0x1d6bb00
");

extern "C" u32 DAT_01d6bb00;

typedef void (*code)(u32, u32, u32);

void func_001dc488(u32 param_1)
{
  u32 iVar1;
  iVar1 = *(u32 *)DAT_01d6bb00;
  (*(code *)(*(u32 *)iVar1))(iVar1, param_1, 0);
  asm volatile ("");
}
