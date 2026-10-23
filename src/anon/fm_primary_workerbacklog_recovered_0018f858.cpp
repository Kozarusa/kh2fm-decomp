#include "../common/types.h"

extern "C" u32 func_001a4550(u32, u32);

void func_0018f858(u32 *param_1)
{
  u32 uVar1;
  uVar1 = func_001a4550(*param_1, param_1[1]);
  *param_1 = uVar1;
}
