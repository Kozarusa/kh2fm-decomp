#include "../common/types.h"

extern "C" void func_001386e0(u32, u32, u32, u32, u32, u32);

void func_00158050(u32 p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7)
{
  u32 uVar1;
  uVar1 = p1 + 408;
  asm volatile ("");
  func_001386e0(p1, p2, p3, p4, p5, p7);
  *(u32 *)uVar1 = p6;
  return;
}
