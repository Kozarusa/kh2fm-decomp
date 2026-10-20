#include "../common/types.h"
extern "C" void func_002f3490(...);

u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  u32 uVar1;
  if (param_2 == 1) {
    uVar1 = *param_1;
    uVar1 = uVar1 >> 8;
    uVar1 = uVar1 & 1;
    return uVar1;
  }
  func_002f3490();
  uVar1 = 0;
  return uVar1;
}
