#include "../common/types.h"

asm(".globl DAT_0033bb1c\n\tDAT_0033bb1c = 0x33bb1c\n");

typedef void (*code)(u32, u32, u32);

extern "C" u32 DAT_0033bb1c;

void func_001050d8(u32 param_1)
{
  code pcVar1;
  pcVar1 = *(code *)DAT_0033bb1c;
  pcVar1(DAT_0033bb1c, param_1, (u32)__builtin_return_address(0));
  asm volatile ("");
}
