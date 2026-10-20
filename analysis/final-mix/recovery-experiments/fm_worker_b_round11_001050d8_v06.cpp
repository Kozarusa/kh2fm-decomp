#include "../common/types.h"

asm(".globl DAT_0033bb1c
	DAT_0033bb1c = 0x33bb1c
");

extern "C" u32 DAT_0033bb1c;

typedef void (*code)(u32, u32, u32);

void func_001050d8(u32 param_1)
{
  u32 iVar1;
  iVar1 = *(u32 *)DAT_0033bb1c;
  (*(code *)(*(u32 *)iVar1))(iVar1, param_1, (u32)__builtin_return_address(0));
  asm volatile ("");
}
