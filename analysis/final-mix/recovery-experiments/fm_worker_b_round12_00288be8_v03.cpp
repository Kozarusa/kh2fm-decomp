#include "../common/types.h"

asm(".globl DAT_0036f34c
	DAT_0036f34c = 0x36f34c
");

extern "C" u32 DAT_0036f34c;

typedef void (*code)(u32, u32, u32);

void func_00288be8(u32 param_1)
{
  u32 iVar1;
  code pcVar2;
  iVar1 = *(u32 *)DAT_0036f34c;
  pcVar2 = *(code *)(*(u32 *)iVar1);
  pcVar2(iVar1, param_1, (u32)__builtin_return_address(0));
  asm volatile ("");
}
