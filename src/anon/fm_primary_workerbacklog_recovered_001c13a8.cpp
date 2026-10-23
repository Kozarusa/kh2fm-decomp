#include "../common/types.h"

extern "C" void func_001dc920(u32);
extern "C" void func_00105110(u32);
extern "C" void func_001db7d0(u32);

void func_001c13a8(u32 *param_1)
{
  func_001dc920(*param_1);
  func_00105110(param_1[12]);
  func_001db7d0(param_1 + 5);
  asm volatile ("");
  return;
}
