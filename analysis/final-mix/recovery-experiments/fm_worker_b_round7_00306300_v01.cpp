#include "../common/types.h"

extern "C" void func_3053f0();

void func_00306300(void)
{
  func_3053f0();
  asm volatile("sync");
}
