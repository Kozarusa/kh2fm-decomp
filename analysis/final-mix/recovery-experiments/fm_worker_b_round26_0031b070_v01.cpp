#include "../common/types.h"

#include "../common/types.h"

extern "C" void func_00239870(u32);

void func_0031b070(u32 param_1)
{
  u32 *puVar1;
  puVar1 = (u32 *)param_1;
  *puVar1 = 0x348590;
  *(u32 *)((u8 *)puVar1 + 260) = 0x347e60;
  func_00239870((u32)(long)((u8 *)puVar1 + 284));
  asm volatile ("" ::: "memory");
  *puVar1 = 0x347f98;
  *(u32 *)((u8 *)puVar1 + 260) = 0x347f98;
  return;
}
