#include "../common/types.h"

typedef void (*code)(u32);

void func_00171348(u32 param_1)
{
  u32 iVar1;
  iVar1 = *(u32 *)param_1;
  param_1 = *(u32 *)(iVar1 + 4);
  iVar1 = *(u32 *)param_1;
  (*(code *)(iVar1 + 0x44))(param_1);
}
