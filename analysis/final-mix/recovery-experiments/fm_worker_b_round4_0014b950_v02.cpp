#include "../common/types.h"

void func_0014b950(u32 param_1,short param_2,short param_3,u32 param_4,u32 param_5)
{
  s64 lVar1;
  s64 lVar2;
  s64 lVar3;
  lVar1 = (s64)((int)param_2 + (int)(param_4 & 0xffff) + -1) << 0x10;
  lVar2 = (s64)((int)param_3 + (int)(param_5 & 0xffff) + -1) << 0x30;
  lVar3 = lVar1 | lVar2;
  *(s64 *)(param_1 + 0x10) = ((s64)param_2 | lVar1) | ((s64)param_3 << 0x20 | lVar2);
  return;
}
