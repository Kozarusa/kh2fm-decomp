#include "../common/types.h"

void func_0028af90(u16 *param_1,s32 param_2)
{
  u32 uVar1;
  if (param_2 >= 0) {
    uVar1 = (u32)param_2;
  }
  else {
    uVar1 = param_1[2];
  }
  *(u16 *)((char *)param_1 + 0x16) = (u16)uVar1;
}
