#include "../common/types.h"

asm(".globl DAT_004f6288
	DAT_004f6288 = 0x4f6288
");

extern "C" u32 DAT_004f6288;

typedef void (*code)(u32, u32, u32);

void func_0016c7a0(u32 param_1)
{
  u32 iVar1;
  code pcVar2;
  iVar1 = *(u32 *)DAT_004f6288;
  pcVar2 = *(code *)(*(u32 *)iVar1);
  pcVar2(iVar1, param_1, (u32)__builtin_return_address(0));
  asm volatile ("");
}
