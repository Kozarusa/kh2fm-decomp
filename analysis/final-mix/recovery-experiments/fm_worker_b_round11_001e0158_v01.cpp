#include "../common/types.h"

asm(".globl DAT_01dae340\n\tDAT_01dae340 = 0x1dae340\n");

typedef void (*code)(u32, u32);

extern "C" u32 DAT_01dae340;

void func_001e0158(u32 param_1)
{
  code pcVar1;
  pcVar1 = *(code *)DAT_01dae340;
  pcVar1(DAT_01dae340, param_1);
  asm volatile ("");
}
