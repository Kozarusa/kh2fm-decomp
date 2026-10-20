#include "../common/types.h"

extern "C" void func_002f3f88(u32,u32);
extern "C" u8 D_00354bc0[];
extern "C" u8 D_00354be0[];

void func_002006b0(u32 param_1, u32 param_2)
{
  u32 *link;
  // why: the original loads the nested field in t6
  register u32 offset asm("$14");
  u32 base;
  link = *(u32 **)(param_2 + 12);
  offset = *(u32 *)((u8 *)link + 4);
  base = param_1 + offset;
  func_002f3f88(base + 160, (u32)(long)D_00354bc0);
  base = base + 176;
  func_002f3f88(base, (u32)(long)D_00354be0);
  // why: keeps the second call a real jal so the epilogue stays after it
  asm volatile("");
  return;
}