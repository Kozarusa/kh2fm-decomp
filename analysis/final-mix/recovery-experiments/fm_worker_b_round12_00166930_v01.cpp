#include "../common/types.h"


extern "C" void func_001666a0(u32);

void func_00166930(u32 param_1)
{
  func_001666a0(param_1);
  *(u16 *)(param_1 + 10) = 1;
  *(u8 *)(param_1 + 0xe) = 1;
  *(u16 *)(param_1 + 12) = 1;
}
