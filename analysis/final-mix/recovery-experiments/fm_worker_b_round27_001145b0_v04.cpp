#include "../common/types.h"

/* 001145b0 - v04. v02/v03 emit two spurious prologue words, `sll a0,a0,16` and
 * `srl a0,a0,0`, i.e. GCC re-normalises the incoming parameter through a0 as if
 * it only had 16 significant bits. v04 declares the parameter as s32 so the
 * comparison needs no normalisation at all; the callee is declared taking an s32
 * so the implicit conversion also stays a no-op. */

extern "C" u32 func_00114738(void);
extern "C" s16 D_00345d30[8];

s32 func_001145b0(s32 param_1)
{
  s16 *psVar3 = D_00345d30;
  s32 iVar2 = 0;
  do {
    s16 sVar1 = *psVar3;
    if (sVar1 == param_1) return iVar2;
    psVar3 = psVar3 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 7);
  return func_00114738() + 7;
}
