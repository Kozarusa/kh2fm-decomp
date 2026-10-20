#include "../common/types.h"

extern "C" void func_001678f0(u32);
extern "C" char func_0034d3c0;

void func_00167b60(void)
{
  u32 uVar1;
  uVar1 = (u32)(long)&func_0034d3c0;
  func_001678f0(uVar1);
  func_001678f0(uVar1 + 384);
  return;
}
