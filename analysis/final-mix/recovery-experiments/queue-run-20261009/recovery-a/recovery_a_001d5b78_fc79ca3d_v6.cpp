#include "../common/types.h"
extern "C" u32 *D_01d5ba70;
extern "C" char D_003217a0;
extern "C" void func_002fd248(u32,u32,u32,u32,u32);

void func_001d5b78(u32 param_1, u32 param_2)
{
  asm volatile ("" : : "r"(param_1));
  u32 *puVar1 = D_01d5ba70;
  func_002fd248(param_1 << 4 | param_2, (u32)(long)(puVar1 + 2), *(u32 *)((u32 *)puVar1 + 1), 8, (s32)(long)&D_003217a0);
  asm volatile ("" ::: "memory");
  return;
}
