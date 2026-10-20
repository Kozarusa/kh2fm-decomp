#include "../common/types.h"

extern "C" u32 func_001386e0(void);

void func_00158050(u32 param_1, u32 param_2, u32 param_3)
{
  u32 uVar1;
  uVar1 = param_2;
  func_001386e0();
  *(u32 *)(param_1 + 0x198) = uVar1;
  return;
}
