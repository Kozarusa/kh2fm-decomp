#include "../common/types.h"

s64 func_00152598(u32 param_1,s32 param_2,long param_3,u32 param_4)
{
  u32 *puVar1 = (u32 *)(param_2 * 8 + param_4);
  if (param_3 == 0) {
    return puVar1[0];
  }
  return puVar1[1];
}
