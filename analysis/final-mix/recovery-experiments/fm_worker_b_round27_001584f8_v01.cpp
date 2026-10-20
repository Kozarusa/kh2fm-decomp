#include "../common/types.h"

/* 001584f8 - v01. Same body as 00158450 with a different callee; the load sits
 * 16 bytes into the selected entry, i.e. index i + 2 of the same 64-bit table. */

extern "C" u32 func_00242ce8(void);
extern "C" u64 D_0034a970;

u64 func_001584f8(u64 *param_1)
{
  u32 iVar1 = func_00242ce8();
  return (*param_1 & ((u64 *)&D_0034a970)[iVar1 + 2]) != 0;
}
