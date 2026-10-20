#include "../common/types.h"

#include "../common/types.h"

extern "C" void func_002f3f88(u32,u32);
extern "C" char func_00354bc0;
extern "C" char func_00354be0;

void func_00209e80(u32 param_1, u32 param_2)
{
  u32 table = *(u32 *)(param_2 + 12);
  s32 offset = *(s32 *)(table + 4);
  u32 uVar1 = param_1 + offset;
  func_002f3f88(uVar1 + 224, (u32)(long)&func_00354bc0);
  func_002f3f88(uVar1 + 240, (u32)(long)&func_00354be0);
  asm volatile ("" ::: "$31");
  return;
}
