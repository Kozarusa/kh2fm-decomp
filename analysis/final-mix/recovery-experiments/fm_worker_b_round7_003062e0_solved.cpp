#include "../common/types.h"

extern "C" void func_003053e0();

void func_003062e0(void)
{
  func_003053e0();
  asm volatile("sync");
}
