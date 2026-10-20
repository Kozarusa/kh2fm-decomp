#include "../common/types.h"


typedef void (*code)(u32, u32, u32);

void func_001721d8(u32 *param_1)
{
  u32 iVar1;
  u32 iVar2;
  u32 iVar3;
  iVar1 = *(u32 *)param_1;
  iVar2 = param_1[1];
  iVar3 = *(u32 *)(iVar1 + 4);
  iVar1 = param_1[3];
  (*(code *)(*(u32 *)iVar1 + 8))(iVar1, iVar3, iVar2);
  asm volatile ("");
}
