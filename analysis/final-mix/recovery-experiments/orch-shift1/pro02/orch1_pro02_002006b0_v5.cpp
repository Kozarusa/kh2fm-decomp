#include "../common/types.h"

extern "C" void func_002f3f88(u32,u32);
extern "C" u8 D_00354bc0[];
extern "C" u8 D_00354be0[];

void func_002006b0(u32 param_1, u32 param_2)
{
  u32 *puVar1;
  u32 uVar1;
  u32 uVar2;
  puVar1 = (u32 *)param_2;
  uVar1 = *(u32 *)(puVar1 + 3);
  // why: keeps the outer load in a caller-saved register instead of s0
  asm volatile("" : "+r"(uVar1));
  uVar2 = *(u32 *)(uVar1 + 1);
  uVar1 = uVar2 + param_1;
  func_002f3f88(uVar1 + 160, (u32)(long)D_00354bc0);
  func_002f3f88(uVar1 + 176, (u32)(long)D_00354be0);
  // why: keeps the second call a real jal so the epilogue stays after it
  asm volatile("");
  return;
}