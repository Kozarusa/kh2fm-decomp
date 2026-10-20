#include "../common/types.h"

#include "../common/types.h"

extern "C" u16 func_001b8e88(u16);
extern "C" void func_001bd918(u32,u32,u32);

void func_001bd8c8(u32 param_1)
{
  u32 *puVar1;
  u32 *puVar2;
  u32 uVar1;
  puVar1 = (u32 *)((u8 *)param_1 + 2240);
  puVar1 = (u32 *)puVar1[0];
  puVar2 = puVar1;
  uVar1 = puVar2[27];
  puVar2 = (u32 *)((u8 *)puVar2 + uVar1 * 12);
  func_001bd918(param_1, func_001b8e88(*(u16 *)((u8 *)puVar2 + 14)), 0);
  return;
}
