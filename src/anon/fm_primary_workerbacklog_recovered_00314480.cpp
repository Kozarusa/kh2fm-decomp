#include "../common/types.h"

extern "C" void func_003146c8(u32 *);

void func_00314480(u32 param_1, u32 param_2, u32 param_3, u64 param_4)
{
  s32 local_8[5];
  local_8[0] = param_1;
  local_8[1] = param_2;
  local_8[2] = param_3;
  *(u64 *)(local_8 + 4) = param_4;
  func_003146c8((u32 *)local_8);
}
