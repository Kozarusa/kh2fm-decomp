#include "../common/types.h"

typedef void (*code)(u32, u32, u32, u32);

void func_00185a68(u32 param_1)
{
  u32 iVar1;
  param_1 = *(u32 *)(param_1 + 0x9f4);
  iVar1 = *(u32 *)param_1;
  (*(code *)(iVar1 + 0x50))(param_1, param_1, param_1, param_1);
}
