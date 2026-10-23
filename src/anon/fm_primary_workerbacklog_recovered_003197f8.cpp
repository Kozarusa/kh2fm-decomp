#include "../common/types.h"

typedef void (*code)(u32);

void func_003197f8(u32 param_1)
{
  u32 iVar1;
  param_1 = *(u32 *)(param_1 + 4);
  iVar1 = *(u32 *)param_1;
  (*(code *)(iVar1 + 4))(param_1);
}
