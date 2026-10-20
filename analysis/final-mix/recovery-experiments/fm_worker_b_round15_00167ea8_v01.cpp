#include "../common/types.h"

extern "C" void func_00167e00(u32);
extern "C" char func_0034d6c0;

void func_00167ea8(void)
{
  u32 uVar1;
  uVar1 = (u32)(long)&func_0034d6c0;
  func_00167e00(uVar1);
  func_00167e00(uVar1 + 96);
  return;
}
