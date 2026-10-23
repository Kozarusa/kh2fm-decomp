#include "../common/types.h"

extern "C" void func_003053c0();

void func_003062a0(void)
{
  func_003053c0();
  asm volatile("sync");
}
