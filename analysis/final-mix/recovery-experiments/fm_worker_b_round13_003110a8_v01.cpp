#include "../common/types.h"

extern "C" void func_00305a50(u32, u32 *);

void func_003110a8(u32 param_1, u32 param_2, u32 param_3)
{
  s32 local_8[4];
  local_8[0] = param_1 & 0xff;
  local_8[1] = param_2;
  local_8[2] = param_3;
  func_00305a50(32, (u32 *)local_8);
}
