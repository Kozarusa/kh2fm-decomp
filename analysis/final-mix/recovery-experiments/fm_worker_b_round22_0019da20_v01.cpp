#include "../common/types.h"

extern "C" void func_001bc688(u32);
extern "C" void func_00190128(u32);
void func_0019da20(u32 *param_1, u32 param_2)
{
  *param_1 = param_2;
  *(u16 *)((u8 *)param_1 + 4) = 0;
  func_001bc688((u32)(long)((u8 *)param_1 + 4));
  func_00190128((u32)(long)((u8 *)param_1 + 16));
  *(u32 *)(param_1 + 20) = 0;
  *(u32 *)(param_1 + 9) = 0xffffffff;
  *(u32 *)(param_1 + 15) = 0;
  return;
}
