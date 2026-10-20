#include "../common/types.h"

asm(".globl DAT_0035dc98
	DAT_0035dc98 = 0x35dc98
");

extern "C" u32 DAT_0035dc98;

typedef void (*code)(u32, u32, u32);

void func_0016fac8(u32 param_1)
{
  u32 iVar1;
  code pcVar2;
  iVar1 = *(u32 *)DAT_0035dc98;
  pcVar2 = *(code *)(*(u32 *)iVar1);
  pcVar2(iVar1, param_1, (u32)__builtin_return_address(0));
  asm volatile ("");
}
