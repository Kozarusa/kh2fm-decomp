#include "../common/types.h"

asm(".globl DAT_0035dc98\n\tDAT_0035dc98 = 0x35dc98\n");

typedef void (*code)(u32, u32, u32);

extern "C" u32 DAT_0035dc98;

void func_0016fac8(u32 param_1)
{
  code pcVar1;
  pcVar1 = *(code *)DAT_0035dc98;
  pcVar1(DAT_0035dc98, param_1, (u32)__builtin_return_address(0));
  asm volatile ("");
}
