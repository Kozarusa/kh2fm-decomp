#include "../common/types.h"

extern "C" void func_00108698(u32);
extern "C" void func_001ddd10(u32);

void func_00322ba8(u32 param_1)
{
  func_00108698(param_1 + 0x38);
  func_001ddd10(param_1 + 0xc0);
  asm volatile ("");
  return;
}
