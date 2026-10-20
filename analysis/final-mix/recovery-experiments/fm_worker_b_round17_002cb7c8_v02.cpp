#include "../common/types.h"

extern "C" u64 func_002cb890(u32, u32);

u32 func_002cb7c8(u32 *param_1, u32 param_2, u32 param_3)
{
  u64 local_8;
  local_8 = *(u64 *)(long)func_002cb890(param_2, param_3);
  *(u64 *)(long)param_1 = local_8;
  asm volatile ("" ::: "memory");
  return (u32)param_1;
}
