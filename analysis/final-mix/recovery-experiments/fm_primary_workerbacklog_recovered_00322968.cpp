#include "../common/types.h"

typedef void (*code)(u32);

void func_00322968(u32 param_1)
{
  u32 iVar2;
  code pcVar2;
  iVar2 = *(u32 *)param_1;
  pcVar2 = *(code *)(iVar2 + 0x14);
  pcVar2(param_1);
  asm volatile ("");
}
