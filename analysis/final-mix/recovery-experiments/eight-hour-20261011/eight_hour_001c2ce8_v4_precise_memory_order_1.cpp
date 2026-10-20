#include "../common/types.h"

extern "C" void func_001d7cd0(u32,u64,u64);
extern "C" u8 D_00351468;

void func_001c2ce8(u32 param_1,u64 second,u64 third)
{
  u32 uVar2;
  u32 uVar1;
  func_001d7cd0(param_1,second,third);
  uVar2 = *(u32 *)((u8 *)param_1 + 2748);
  uVar2 = uVar2 | 4;
  uVar1 = *(u32 *)((u8 *)param_1 + 1416);
  uVar1 = uVar1 | 0x200000;
  *(u32 *)((u8 *)param_1 + 1416) = uVar1;
  *(u32 *)param_1 = (u32)&D_00351468;
 asm("" : : "m"(*(u32*)param_1),"m"(*(u32*)((u8*)param_1+2748)));
  *(u32 *)((u8 *)param_1 + 2748) = uVar2;
  return;
}
