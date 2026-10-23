#include "../common/types.h"

extern "C" u32 func_001058e8(void);

void func_00242b10(u32 param_1)
{
  u32 *puVar1;
  s32 sVar2;
  sVar2 = (s32)((param_1 & 0xff) != 0);
  puVar1 = (u32 *)((u8 *)func_001058e8() + 16800);
  puVar1[1] = (puVar1[1] & 0xfffffff7) | ((u32)sVar2 << 3);
  return;
}
