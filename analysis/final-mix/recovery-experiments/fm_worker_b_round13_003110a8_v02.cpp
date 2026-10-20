#include "../common/types.h"

extern "C" void func_00305a50(u32, u32 *);

void func_003110a8(u32 param_1, u32 param_2, u32 param_3)
{
  u32 local_20[8];
  local_20[1] = param_2;
  local_20[0] = param_1 & 0xff;
  func_00305a50(32, local_20 + 8);
}
