#include "../common/types.h"

extern "C" void func_001991a8(s32,s32);

void func_001ac700(u32 *param_1)
{
  u32 uVar1;
  uVar1 = param_1[0x20];
  param_1[0x1c] = 4;
  func_001991a8(0x22,(s32)uVar1);
}
