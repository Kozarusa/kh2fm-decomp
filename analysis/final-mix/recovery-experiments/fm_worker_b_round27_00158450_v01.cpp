#include "../common/types.h"

/* 00158450 - v01
 * lui t7,0x35 ; addiu t7,t7,-22160 is an address materialisation, so the
 * assembler %hi rounding applies: 0x34a970 + 0x8000 >> 16 == 0x35, matching the
 * target. The table is 64-bit and the index is scaled by 8 (sll v0,3). */

extern "C" u32 func_00242d58(void);
extern "C" u64 D_0034a970;

u64 func_00158450(u64 *param_1)
{
  u32 iVar1 = func_00242d58();
  return (*param_1 & ((u64 *)&D_0034a970)[iVar1]) != 0;
}
