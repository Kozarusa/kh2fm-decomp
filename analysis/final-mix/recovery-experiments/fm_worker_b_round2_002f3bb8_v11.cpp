#include "../common/types.h"
extern "C" void func_002f3490(...);

u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  u32 uVar1;
  switch (param_2) {
    case 1:
      uVar1 = *param_1;
      uVar1 = uVar1 >> 8;
      uVar1 = uVar1 & 1;
      break;
    default:
      func_002f3490();
      uVar1 = 0;
      break;
  }
  return uVar1;
}
