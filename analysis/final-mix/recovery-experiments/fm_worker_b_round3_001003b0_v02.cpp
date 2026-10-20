#include "../common/types.h"

extern "C" void func_002f3490(void) __attribute__((const));

void func_001003b0(void)
{
  func_002f3490();
  asm volatile("" ::: "memory");
}
