#include "../common/types.h"

typedef void (*code)(u32);

void func_0031f940(u32 param_1)
{
  u32 iVar1;
  param_1 = *(u32 *)(param_1 + 0x18);
  iVar1 = *(u32 *)param_1;
  (*(code *)(iVar1 + 0x10))(param_1);
}
