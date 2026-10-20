#include "../common/types.h"

/* 001145b0 - v01. Seven-entry linear search over a short table; the miss path
 * tail-returns func_00114738() + 7. lui 0x34 ; addiu t4,t7,23856 is an address
 * materialisation: 0x345d30 + 0x8000 >> 16 == 0x34, matching the target. */

extern "C" u32 func_00114738(void);
extern "C" s16 D_00345d30;

s32 func_001145b0(s16 param_1)
{
  s16 *psVar3 = (s16 *)&D_00345d30;
  s16 sVar1 = *psVar3;
  s32 iVar2 = 0;
  while (1) {
    if (sVar1 == param_1) return iVar2;
    if (7 <= iVar2 + 1) break;
    psVar3 = psVar3 + 1;
    sVar1 = *psVar3;
    iVar2 = iVar2 + 1;
  }
  iVar2 = func_00114738();
  return iVar2 + 7;
}
