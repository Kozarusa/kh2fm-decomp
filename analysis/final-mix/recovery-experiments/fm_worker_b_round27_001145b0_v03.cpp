#include "../common/types.h"

/* 001145b0 - v03. v02's loop body is already word-for-word correct; the only
 * defect is two spurious words, `sll a0,a0,16` and `srl a0,a0,0`, i.e. GCC
 * normalising the incoming short through a0. v03 declares the table as an
 * array of s16 rather than casting the address of a scalar, so the element type
 * is visible to GCC and the normalisation should not be needed. */

extern "C" u32 func_00114738(void);
extern "C" s16 D_00345d30[8];

s32 func_001145b0(s16 param_1)
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
