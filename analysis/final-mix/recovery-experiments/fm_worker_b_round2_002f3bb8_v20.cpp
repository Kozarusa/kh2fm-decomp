#include "../common/types.h"
extern "C" void func_002f3490(...);

u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  u32 uVar1;
  u32 uVar2;
  uVar1 = 1;
  if (param_2 == uVar1) {
    uVar2 = *param_1;
    uVar2 = uVar2 >> 8;
    uVar1 = uVar2 & 1;
  }
  else {
    func_002f3490();
    uVar1 = 0;
  }
  return uVar1;
}
