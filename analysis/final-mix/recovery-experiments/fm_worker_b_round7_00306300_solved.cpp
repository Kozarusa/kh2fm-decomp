#include "../common/types.h"

extern "C" void func_003053f0();

void func_00306300(void)
{
  func_003053f0();
  asm volatile("sync");
}
