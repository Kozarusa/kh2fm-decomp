extern "C" char D_00359910;
#include "../common/types.h"

extern "C" u32 D_003591c8;

extern "C" void func_002f25a0(u32, u32);
extern "C" void func_002f3918(u32, u32);

void func_0020f150(void)
{
  func_002f25a0(0, 0);
  func_002f3918(D_003591c8, (u32)&D_00359910);
  asm volatile ("");
}
