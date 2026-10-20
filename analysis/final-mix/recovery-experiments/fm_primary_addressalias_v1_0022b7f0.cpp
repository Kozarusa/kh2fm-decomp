#include "../common/types.h"

extern "C" void func_002fee78(u32,u32,u32);
extern "C" void func_002ff3fc(u32);
extern "C" char func_01dad938;

extern "C" char func_00371138;

extern "C" volatile u32 D_0033caf4;
u32 func_0022b7f0(void)
{
  u32 uVar1;
  uVar1 = (u32)(long)&func_01dad938;
  func_002fee78(uVar1, (u32)(long)&func_00371138, D_0033caf4);
  func_002ff3fc(uVar1);
  return uVar1;
}
