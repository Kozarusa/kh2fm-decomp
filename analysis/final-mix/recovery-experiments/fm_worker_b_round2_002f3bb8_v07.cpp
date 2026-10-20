#include "../common/types.h"
extern "C" void func_002f3490(...);

bool func_002f3bb8(u32 *param_1,s32 param_2)
{
  bool bVar1;
  bVar1 = false;
  if (param_2 == 1) {
    bVar1 = (*param_1 & 0x100) != 0;
  } else {
    func_002f3490();
  }
  return bVar1;
}
