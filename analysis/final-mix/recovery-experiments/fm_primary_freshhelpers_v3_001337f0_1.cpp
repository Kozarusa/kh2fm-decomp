#include "../common/types.h"
// Provisional decompiler recovery; exactness requires independent proof.
int func_001337f0(int *param_1,u32 param_2,u32 param_3)
{
  int iVar1;
  *(u8 *)(*param_1 + 2) = 0;
  *(u32 *)(*param_1 + 8) = param_3;
  *(u32 *)(*param_1 + 0xc) = param_2 | 0x50000000;
  *(u8 *)(*param_1 + 3) = 0x10;
  *(u32 *)(*param_1 + 4) = 0;
  *(volatile short *)*param_1 = (short)param_2;
  iVar1 = *(volatile int *)param_1;
  *param_1 = iVar1 + param_2 * 0x10 + 0x10;
  return iVar1 + 0x10;
}
