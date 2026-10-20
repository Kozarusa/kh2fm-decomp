#include "../common/types.h"

extern "C" void func_002d10a0(u32);

void func_002dd790(u32 param_1)
{
  u32 uVar1;
  u32 uVar2;
  func_002d10a0(param_1);
  uVar1 = param_1 + 1344;
  uVar2 = param_1 + 3056;
  if (uVar2 != uVar1) {
    *(u64 *)(long)uVar2 = *(u64 *)(long)uVar1;
    asm volatile ("" ::: "memory");
  }
  return;
}
