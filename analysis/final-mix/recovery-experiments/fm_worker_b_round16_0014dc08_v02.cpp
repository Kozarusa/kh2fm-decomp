#include "../common/types.h"

extern "C" void func_001666a0(void);

void func_0014dc08(u32 param_1)
{
  func_001666a0();
  *(volatile u8 *)(param_1 + 0x1d9) = 0;
  *(volatile u32 *)(param_1 + 0x1d0) = 0;
  *(volatile u16 *)(param_1 + 0x1d4) = 0;
  *(volatile u8 *)(param_1 + 0x1d6) = 0;
  *(volatile u8 *)(param_1 + 0x1d7) = 0;
  *(volatile u8 *)(param_1 + 0x1d8) = 0;
  return;
}
