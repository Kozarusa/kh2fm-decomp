#include "../common/types.h"

/* 001145b0 - v05. v04 removed the normalisation by declaring the parameter s32,
 * but s32 is the wrong width for the sign-extended `lh` comparison. v05 keeps
 * the comparison at s16 and instead types the table as s16 while the parameter
 * is read through a signed char pointer, so the natural promotion of both sides
 * is a plain sign extension the compiler already has. */

extern "C" u32 func_00114738(void);
extern "C" s16 D_00345d30[8];

s32 func_001145b0(s16 param_1)
{
  s32 iVar2;
  s16 *psVar3;
  iVar2 = 0;
  psVar3 = D_00345d30;
  do {
    if (*psVar3 == param_1) return iVar2;
    psVar3 = psVar3 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 7);
  return func_00114738() + 7;
}
