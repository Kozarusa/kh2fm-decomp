#include "../common/types.h"

asm(".globl DAT_01d6bb00\n\tDAT_01d6bb00 = 0x1d6bb00\n");

typedef void (*code)(u32, u32);

extern "C" u32 DAT_01d6bb00;

void func_001dc4b8(u32 param_1)
{
  code pcVar1;
  pcVar1 = *(code *)DAT_01d6bb00;
  pcVar1(DAT_01d6bb00, param_1);
  asm volatile ("");
}
