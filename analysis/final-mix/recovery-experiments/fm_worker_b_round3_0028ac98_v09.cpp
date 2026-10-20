#include "../common/types.h"

s32 func_0028ac98(s16 *param_1,s32 param_2)
{
  s32 iVar1;
  if (param_2 == *param_1) {
    iVar1 = *(s32 *)((char *)param_1 + 0x30);
  }
  else {
    iVar1 = *(s32 *)((char *)param_1 + 0x2c);
  }
  return iVar1 + param_2 * 8;
}
