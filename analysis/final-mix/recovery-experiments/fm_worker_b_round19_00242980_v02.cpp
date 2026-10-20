#include "../common/types.h"

extern "C" u32 func_001058e8(void);

void func_00242980(s32 *param_1, s32 *param_2)
{
  u32 uVar1;
  s32 *puVar1;
  s32 *puVar2;
  uVar1 = func_001058e8();
  puVar1 = param_1;
  puVar2 = param_2;
  *puVar1 = *(s16 *)(uVar1 + 0x41a0);
  asm volatile ("");
  *puVar2 = *(s16 *)(uVar1 + 0x41a2);
  return;
}
