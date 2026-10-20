#include "../common/types.h"

extern "C" u64 func_002b6708(s32 param_1, s32 param_2, u32 param_3);

u64 func_002b7108(u32 param_1)
{
  u32 local_1;
  u64 uVar1;
  local_1 = param_1;
  uVar1 = func_002b6708(2, 18, local_1);
  return uVar1;
}
