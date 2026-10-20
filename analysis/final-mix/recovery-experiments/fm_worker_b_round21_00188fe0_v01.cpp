#include "../common/types.h"

extern "C" u64 func_001b7818(u32);

u32 func_00188fe0(u32 param_1, u32 param_2)
{
  u64 uVar1;
  uVar1 = func_001b7818(param_2);
  if (uVar1 == 0) { return 0; }
  return param_1 + 276 * uVar1 - 276;
}
