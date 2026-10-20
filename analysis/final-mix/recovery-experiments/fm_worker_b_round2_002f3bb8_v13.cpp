#include "../common/types.h"
extern "C" void func_002f3490(...);

u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  if (param_2 == 1) {
    return (*param_1 >> 8) & 1;
  }
  func_002f3490();
  return 0u;
}
