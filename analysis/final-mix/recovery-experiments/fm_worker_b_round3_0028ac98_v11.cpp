#include "../common/types.h"

s32 func_0028ac98(s16 *param_1,s32 param_2)
{
  s32 iVar1;
  s32 iVar2;
  s32 iVar3 = *(s32 *)((char *)param_1 + 0x2c);
  asm("" : "+r"(iVar3));
  iVar2 = param_2 * 8;
  if (param_2 == *param_1) {
    iVar3 = *(s32 *)((char *)param_1 + 0x30);
    asm("" : "+r"(iVar3));
  }
  iVar1 = iVar2 + iVar3;
  return iVar1;
}
