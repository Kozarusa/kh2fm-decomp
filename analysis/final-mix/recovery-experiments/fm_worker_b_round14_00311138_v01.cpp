#include "../common/types.h"

extern "C" void func_00305a50(s32, u32 *);

void func_00311138(u32 param_1, u32 param_2, u32 param_3)
{
  u32 local_20[3];
  u32 uVar1;
  uVar1 = param_2;
  local_20[1] = uVar1;
  local_20[0] = param_1;
  local_20[2] = param_3 & 0xffff;
  func_00305a50(-6, (u32 *)local_20);
  return;
}
