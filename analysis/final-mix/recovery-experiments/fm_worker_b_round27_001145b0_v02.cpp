#include "../common/types.h"

/* 001145b0 - v02. v01's while(1) with an explicit advance-and-reload compiled to
 * 96 bytes. The target's loop is rotated: the load is at the loop head, the
 * pointer advance is in the branch delay slot and the exit test uses the
 * post-increment counter. That is exactly a do-while whose body loads before it
 * advances (the round-26 00281008 mechanism). */

extern "C" u32 func_00114738(void);
extern "C" s16 D_00345d30;

s32 func_001145b0(s16 param_1)
{
  s16 *psVar3 = (s16 *)&D_00345d30;
  s32 iVar2 = 0;
  do {
    s16 sVar1 = *psVar3;
    if (sVar1 == param_1) return iVar2;
    psVar3 = psVar3 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 7);
  return func_00114738() + 7;
}
