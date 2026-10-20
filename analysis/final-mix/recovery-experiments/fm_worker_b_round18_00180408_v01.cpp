#include "../common/types.h"

extern "C" u32 func_00168b38(u32, u32, u32);

u32 func_00180408(u32 param_1, u32 param_2)
{
  u32 uVar1;
  if (param_2 == 0) {
    uVar1 = 0;
  } else {
    uVar1 = func_00168b38(param_2, 9, 0);
    if (uVar1 != 0) {
      uVar1 = *(u32 *)(uVar1 + 8);
    } else {
      uVar1 = 0;
    }
  }
  return uVar1;
}
