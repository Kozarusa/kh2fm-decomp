#include "../common/types.h"
extern "C" void func_002f3490(...);

bool func_002f3bb8(u32 *param_1,s32 param_2)
{
  bool bVar1;
  bVar1 = true;
  if (param_2 == 1) {
    bVar1 = (*param_1 >> 8) & 1;
  } else {
    func_002f3490();
    bVar1 = false;
  }
  return bVar1;
}
