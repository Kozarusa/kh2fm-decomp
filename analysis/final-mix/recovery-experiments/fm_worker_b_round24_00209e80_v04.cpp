#include "../common/types.h"

extern "C" void func_002f3f88(u32,u32);
extern "C" char func_00354bc0;
extern "C" char func_00354be0;

void func_00209e80(u32 param_1, u32 param_2)
{
  u32 *puVar1;
  u32 uVar1;
  u32 uVar2;
  puVar1 = (u32 *)param_2;
  uVar1 = *(u32 *)(puVar1 + 3);
  uVar2 = *(u32 *)(uVar1 + 1);
  asm volatile ("" : "+r"(uVar2));
  uVar1 = uVar2 + param_1;
  func_002f3f88(uVar1 + 224, (u32)(long)&func_00354bc0);
  func_002f3f88(uVar1 + 240, (u32)(long)&func_00354be0);
  asm volatile ("");
  return;
}
