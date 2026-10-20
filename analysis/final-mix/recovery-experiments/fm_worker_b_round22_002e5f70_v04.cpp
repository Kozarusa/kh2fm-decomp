#include "../common/types.h"

extern "C" void func_00108398(u32);
void func_002e5f70(u32 param_1)
{
  func_00108398((u32)(long)((u8 *)param_1 + 16));
  func_00108398((u32)(long)((u8 *)param_1 + 288));
  *(volatile u64 *)(param_1 + 0x230) = 0;
  *(volatile u32 *)(param_1 + 0x220) = 0;
  *(volatile u32 *)(param_1 + 0x224) = 0;
  *(volatile u32 *)(param_1 + 0x228) = 0;
  *(volatile u32 *)(param_1 + 0x22c) = 0;
  return;
}
