#include "../common/types.h"

u32 func_00152598(long param_1,int param_2,long param_3,int param_4)
{
  u32 *puVar1 = (u32 *)(param_4 + param_2 * 8);
  if (param_3 == 0) {
    return puVar1[0];
  }
  return puVar1[1];
}
