#include "../common/types.h"

extern "C" void func_001ab598(u32, u32, u32, u32, u32);

void func_001aa940(u32 p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6)
{
  u32 uVar1;
  uVar1 = p1 + 64;
  func_001ab598(*p1, uVar1, p2, p3, p5);
  return;
}
