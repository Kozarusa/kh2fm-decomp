#include "../common/types.h"

extern "C" u8 *func_00170400(u32, u32, u32);

void func_00170530(u32 param_1, u32 param_2, u32 param_3, u32 param_4)
{
  u8 *puVar1;
  u32 iVar1;
  u32 iVar2;
  puVar1 = func_00170400(param_1, param_2, param_4);
  iVar1 = 0xffff;
  iVar2 = 1;
  *(u16 *)(puVar1 + 0x38) = param_3;
  *(u16 *)(puVar1 + 0x3a) = iVar1;
  *(u8 *)puVar1 = iVar2;
  asm volatile ("" ::: "memory");
  return;
}
