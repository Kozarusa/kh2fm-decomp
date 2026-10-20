#include "../common/types.h"

u32 func_00152598(u32 param_1,s32 param_2,long param_3,u32 param_4)
{
  u32 uVar1;
  u32 uVar2;
  u32 *puVar1;
  uVar2 = param_4;
  uVar1 = param_2;
  asm("" : "+r"(uVar2), "+r"(uVar1));
  puVar1 = (u32 *)(uVar1 * 8 + uVar2);
  if (param_3 == 0) {
    return puVar1[0];
  }
  return puVar1[1];
}
