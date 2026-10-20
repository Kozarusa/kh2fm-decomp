#include "../common/types.h"

asm(".globl DAT_0036f3f8
	DAT_0036f3f8 = 0x36f3f8
");

extern "C" u32 DAT_0036f3f8;

typedef void (*code)(u32, u32, u32);

void func_0028cc08(u32 param_1)
{
  u32 iVar1;
  u32 iVar2;
  iVar1 = *(u32 *)DAT_0036f3f8;
  iVar2 = *(u32 *)iVar1;
  (*(code *)iVar2)(iVar1, param_1, (u32)__builtin_return_address(0));
  asm volatile ("");
}
