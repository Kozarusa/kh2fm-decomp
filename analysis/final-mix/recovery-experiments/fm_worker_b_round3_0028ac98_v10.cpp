#include "../common/types.h"

u32 func_0028ac98(s16 *param_1,s32 param_2)
{
  u32 iVar1;
  u32 iVar2;
  iVar2 = (u32)param_2 << 3;
  if (param_2 == *param_1) {
    iVar1 = *(u32 *)((char *)param_1 + 0x30) + iVar2;
  }
  else {
    iVar1 = *(u32 *)((char *)param_1 + 0x2c) + iVar2;
  }
  return iVar1;
}
