#include "../common/types.h"

extern "C" void func_001991a8(s32,s32);

void func_001ac700(s32 *param_1)
{
  *(u32 *)((char *)param_1 + 0x70) = 4;
  func_001991a8(0x22,*(u32 *)((char *)param_1 + 0x80));
}
