#include "../common/types.h"

/* 001584f8 - v02. v01 declared the table as a scalar u64, and GCC then emitted
 * an extra ld t6,0(t7) that materialised the scalar before indexing it. Declaring
 * the symbol as an array removes that load; the index stays scaled by 8. */

extern "C" u32 func_00242ce8(void);
extern "C" u64 D_0034a970[8];

u64 func_001584f8(u64 *param_1)
{
  u32 iVar1 = func_00242ce8();
  return (*param_1 & D_0034a970[iVar1 + 2]) != 0;
}
