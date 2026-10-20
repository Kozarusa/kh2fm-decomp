#include "../common/types.h"

typedef void (*code)(u32, u32, u32, u32);

void func_001231f8(u32 param_1, u32 param_2, u32 param_3)
{
  code pcVar1;
  pcVar1 = *(code *)(*(u32 *)param_1 + 0x4c);
  pcVar1(param_1, param_2 & 0xff, param_2, 0);
  asm volatile ("");
}
