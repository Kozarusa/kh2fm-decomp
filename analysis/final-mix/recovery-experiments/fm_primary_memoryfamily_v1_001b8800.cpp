#include "../common/types.h"

extern "C" volatile u32 D_01d48d90;
extern "C" char func_00320448;

extern "C" void func_002fd248(u32, u32, u32, u32, u32);

void func_001b8800(u32 param_1)
{
  u32 uVar1;
  uVar1 = D_01d48d90;
  func_002fd248(param_1, uVar1 + 8, *(u32 *)(uVar1 + 4), 0x10, (u32)(long)&func_00320448);
  asm volatile ("");
  return;
}
