#include "../common/types.h"

/* 00158450 - v03. v01/v02 both emitted a spurious `ld t6,0(t7)` that loaded the
 * table base as a value. v03 loads the two operands into named temporaries and
 * declares the return as the 32-bit comparison the target actually computes,
 * which is why the target carries dsll32/dsra32 before the return. */

extern "C" u32 func_00242d58(void);
extern "C" u64 D_0035a970[8];

int func_00158450(u64 *param_1)
{
  u32 iVar1 = func_00242d58();
  u64 uVar2 = *param_1;
  u64 uVar3 = D_0035a970[iVar1];
  return (uVar2 & uVar3) != 0;
}
