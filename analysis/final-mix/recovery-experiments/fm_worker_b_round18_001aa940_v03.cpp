#include "../common/types.h"

extern "C" void func_001ab598(u32, u32, u32, u32, u32, u32);

void func_001aa940(u32 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5)
{
  func_001ab598(*(u32 *)param_1, param_1 + 64, param_2, param_3, param_4, param_5);
  return;
}
