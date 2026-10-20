#include "../common/types.h"


extern "C" u32 func_0017f488(s32,s32,float,float,s32,s32);
extern "C" void func_001802d8(u32,u32,u32,u32,u32,u32);

void func_00180c88(u32 param_1,s32 param_2,float param_3)
{
  if (*(int *)(param_1 + 0x100) == 0) {
    func_0017f488(param_1,param_2,param_3,0.0f,param_2,0);
    return;
  }
  func_001802d8(*(u32 *)(param_1 + 0xfc),*(int *)(param_1 + 0x100),
               *(u32 *)(param_1 + 0xf0),*(u32 *)(param_1 + 8),param_2,0);
  return;
}

