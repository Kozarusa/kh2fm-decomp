#include "../common/types.h"

extern "C" void func_3053d0();

void func_003062c0(void)
{
  func_3053d0();
  asm volatile("sync");
}
