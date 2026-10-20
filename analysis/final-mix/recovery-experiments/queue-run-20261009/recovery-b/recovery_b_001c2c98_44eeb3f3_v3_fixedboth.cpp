#include "../common/types.h"

extern "C" void func_001d7cd0(u32);
extern "C" char func_00351468;

void func_001c2c98(u32 param_1)
{
  register u32 uVar2 asm("$14");
  register u32 uVar1 asm("$13");
  func_001d7cd0(param_1);
  uVar2 = *(u32 *)((u8 *)param_1 + 2748);
  uVar2 = uVar2 | 4;
  uVar1 = *(u32 *)((u8 *)param_1 + 1416);
  uVar1 = uVar1 | 0x200000;
  asm("" : "+r"(uVar1), "+r"(uVar2));
  *(volatile u32 *)((u8 *)param_1 + 1416) = uVar1;
  *(volatile u32 *)param_1 = (u32)(long)&func_00351468;
  *(volatile u32 *)((u8 *)param_1 + 2748) = uVar2;
  return;
}
