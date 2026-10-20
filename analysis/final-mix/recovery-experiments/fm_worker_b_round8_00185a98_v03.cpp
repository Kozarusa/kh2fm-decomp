#include "../common/types.h"

typedef void (*code)(u32);

void func_00185a98(u32 param_1)
{
  u32 iVar1;
  param_1 = *(u32 *)(param_1 + 0x9f4);
  iVar1 = *(u32 *)param_1;
  (*(code *)(iVar1 + 0x4c))(param_1);
  asm volatile ("");
}
