#include "../common/types.h"

extern "C" void func_0013dad0(u32);

void func_001a2710(u32 param_1)
{
  u32 *puVar1;
  puVar1 = (u32 *)param_1;
  if ((puVar1[148] & 1) == 1) { func_0013dad0(param_1); puVar1[148] = puVar1[148] & 0xfffffffe; }
  return;
}
