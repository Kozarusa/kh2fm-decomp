#include "../common/types.h"

struct S { u32 a[0x1c]; u32 b; };

extern "C" void func_001991a8(u32,u32);

void func_001ac700(u32 param_1)
{
  S *ps = (S *)param_1;
  ps->a[0x1c] = 4;
  func_001991a8(0x22,ps->b);
}
