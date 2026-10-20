#include "../common/types.h"

typedef void (*code)(u32, u32, u32);

void func_00171810(u32 *param_1)
{
  u32 iVar1;
  u32 iVar2;
  u32 iVar3;
  iVar1 = *(u32 *)param_1;
  iVar3 = param_1[2];
  iVar2 = *(u32 *)(iVar1 + 4);
  iVar1 = param_1[1];
  (*(code *)(*(u32 *)iVar2 + 0x54))(iVar2, iVar1, iVar3);
  asm volatile ("");
}
