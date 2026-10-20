#include "../common/types.h"

asm(".globl PTR_0035dc98\n\tPTR_0035dc98 = 0x35dc98\n");

typedef void (*code)(u32, u32);

extern "C" u32 PTR_0035dc98;

void func_0016fb00(u32 param_1)
{
  code pcVar1;
  pcVar1 = *(code *)PTR_0035dc98;
  pcVar1(PTR_0035dc98, param_1);
  asm volatile ("");
}
