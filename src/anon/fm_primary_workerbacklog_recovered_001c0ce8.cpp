#include "../common/types.h"

extern "C" u32 func_001c0cd8(void);

u32 func_001c0ce8(u32 param_1)
{
  u32 *puVar1;
  u32 *puVar2;
  u32 uVar1;
  s32 iVar1;
  puVar1 = (u32 *)param_1;
  iVar1 = 0;
  if (func_001c0cd8() != 0) {
    puVar2 = (u32 *)puVar1[348];
    uVar1 = puVar2[354] & 0x80;
    asm volatile ("" : "+r"(uVar1));
    iVar1 = (0 < uVar1);
  }
  return iVar1;
}
