#include "../common/types.h"

void func_0014b950(s32 *param_1,s16 param_2,s16 param_3,u16 param_4,u16 param_5)
{
  s64 lVar1;
  s64 lVar2;
  s64 lVar3;
  s64 lVar4;
  lVar2 = (s64)(param_3 + (param_5 & 0xffff) - 1);
  lVar1 = (s64)(param_2 + (param_4 & 0xffff) - 1);
  lVar3 = (s64)param_2 | (lVar2 << 0x30);
  lVar4 = (s64)param_3 << 0x20 | (lVar1 << 0x10);
  *(s64 *)(param_1 + 4) = lVar3 | lVar4;
}
