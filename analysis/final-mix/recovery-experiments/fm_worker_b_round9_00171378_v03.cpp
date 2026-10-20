#include "../common/types.h"

typedef void (*code)(u32);

void func_00171378(u32 param_1)
{
  u32 iVar1;
  u32 iVar2;
  iVar1 = *(u32 *)param_1;
  param_1 = *(u32 *)(iVar1 + 4);
  iVar1 = *(u32 *)param_1;
  iVar2 = iVar1 + 0x48;
  (*(code *)iVar2)(param_1);
  asm volatile ("");
}
