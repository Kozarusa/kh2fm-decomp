#include "../common/types.h"

extern "C" s32 *func_00316d08();

s32 func_00305ce0(void)
{
  s32 *puVar1;
  s32 iVar1;
  puVar1 = func_00316d08();
  iVar1 = 5;
  *puVar1 = iVar1;
  return -1;
}
