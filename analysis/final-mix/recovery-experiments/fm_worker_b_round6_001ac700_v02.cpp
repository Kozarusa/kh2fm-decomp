#include "../common/types.h"

extern "C" void func_001991a8(s32,s32);

void func_001ac700(s32 *param_1)
{
  s32 iVar1;
  *(u32 *)((char *)param_1 + 0x70) = 4;
  iVar1 = *(u32 *)((char *)param_1 + 0x80);
  func_001991a8(0x22,iVar1);
}
