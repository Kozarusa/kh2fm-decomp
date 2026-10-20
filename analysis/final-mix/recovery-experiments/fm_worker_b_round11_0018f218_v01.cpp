#include "../common/types.h"

typedef void (*code)(u32, u32);

void func_0018f218(u32 *param_1)
{
  u32 iVar1;
  u32 iVar2;
  iVar1 = *(u32 *)param_1;
  iVar2 = param_1[1];
  param_1 = (u32 *)(iVar1 + 4);
  (*(code *)(*(u32 *)param_1 + 0x68))(param_1, iVar2);
  asm volatile ("");
}
