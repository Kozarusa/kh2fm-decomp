#include "../common/types.h"

#include "../common/types.h"

extern "C" void func_00239870(u32);

extern "C" char D_00348590;
extern "C" char D_00347e60;
extern "C" char D_00347f98;

void func_0031b070(u32 param_1)
{
  u32 *puVar1;
  puVar1 = (u32 *)param_1;
  *puVar1 = (u32)(long)&D_00348590;
  *(u32 *)((u8 *)puVar1 + 260) = (u32)(long)&D_00347e60;
  func_00239870((u32)(long)((u8 *)puVar1 + 284));
  asm volatile ("" ::: "memory");
  *(u32 *)((u8 *)puVar1 + 260) = (u32)(long)&D_00347f98;
  *puVar1 = (u32)(long)&D_00347f98;
  return;
}
