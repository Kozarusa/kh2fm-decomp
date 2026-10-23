#include "../common/types.h"

/* 001584f8 - v04 (page corrected, as 00158450 v04). v01/v02 both emitted a spurious `ld t6,0(t7)` that loaded the
 * table base as a value. v03 loads the two operands into named temporaries and
 * declares the return as the 32-bit comparison the target actually computes,
 * which is why the target carries dsll32/dsra32 before the return. */

extern "C" u32 func_00242ce8(void);
extern "C" u64 D_0034a970[8];

int func_001584f8(u64 *param_1)
{
  u32 iVar1 = func_00242ce8();
  u64 uVar2 = *param_1;
  u64 uVar3 = D_0034a970[iVar1 + 2];
  return (uVar2 & uVar3) != 0;
}
