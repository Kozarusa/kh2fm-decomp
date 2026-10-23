#include "../common/types.h"
extern "C" void func_002f3f88(u32,u32);
extern "C" u8 D_00354bc0[];
extern "C" u8 D_00354be0[];

void func_002007e0(u32 object, u32 owner)
{
  u32 table = *(u32 *)(owner + 12);
  s32 offset = *(s32 *)(table + 4);
  u32 base = object + offset;
  func_002f3f88(base + 160, (u32)D_00354bc0);
  func_002f3f88(base + 176, (u32)D_00354be0);
  asm volatile ("" ::: "$31"); // why: ra clobber keeps the second call a jal and the ra save first (precedent 00209e80)
  return;
}
