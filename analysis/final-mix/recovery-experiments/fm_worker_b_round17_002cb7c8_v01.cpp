#include "../common/types.h"

typedef struct { u64 q[2]; } __attribute__((aligned(16))) quad_t;

extern "C" quad_t func_002cb890(u32, u32);

u32 func_002cb7c8(u32 *param_1, u32 param_2, u32 param_3)
{
  quad_t local_8;
  local_8 = func_002cb890(param_2, param_3);
  *param_1 = local_8.q[0];
  *(u32 *)(param_1 + 4) = local_8.q[1];
  asm volatile ("" ::: "memory");
  return (u32)param_1;
}
