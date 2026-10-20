#include "../common/types.h"

typedef void (*code)(u32);

extern "C" u32 func_0010c7e8(u32);

void func_002f0798(u32 *param_1)
{
  u32 iVar1;
  u32 iVar2;
  code pcVar2;
  iVar1 = *(u32 *)param_1;
  iVar2 = func_0010c7e8(*(u32 *)(iVar1 + 4));
  pcVar2 = *(code *)(*(u32 *)iVar2 + 0x28);
  pcVar2(iVar2);
  asm volatile ("");
}
