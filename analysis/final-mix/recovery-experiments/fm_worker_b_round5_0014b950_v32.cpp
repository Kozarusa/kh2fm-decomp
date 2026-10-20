#include "../common/types.h"

void func_0014b950(s32 *param_1,s16 param_2,s16 param_3,u32 param_4,u32 param_5)
{
  *(s64 *)(param_1 + 4) = ((s64)param_3 << 0x20) | ((s64)param_2) | ((s64)(s32)((s32)param_2 + (param_4 & 0xffff) + -1) << 0x10) | ((s64)(s32)((s32)param_3 + (param_5 & 0xffff) + -1) << 0x30);
  return;
}
