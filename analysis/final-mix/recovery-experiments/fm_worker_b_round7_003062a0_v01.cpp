#include "../common/types.h"

extern "C" void func_3053c0();

void func_003062a0(void)
{
  func_3053c0();
  asm volatile("sync");
}
