#include "../common/types.h"

s32 func_0028ac98(s16 *param_1,s32 param_2)
{
  s32 *puVar1;
  if (param_2 == *param_1) {
    puVar1 = (s32 *)param_1 + 12;
  }
  else {
    puVar1 = (s32 *)param_1 + 11;
  }
  return *puVar1 + param_2 * 8;
}
