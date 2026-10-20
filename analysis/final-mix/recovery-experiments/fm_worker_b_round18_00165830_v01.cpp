#include "../common/types.h"

typedef struct { u64 q[2]; } __attribute__((aligned(16))) quad_t;

extern "C" void func_00142940(u32, void *);

void func_00165830(u32 param_1, u32 *param_2)
{
  quad_t local_50[4];
  local_50[0] = *(quad_t *)(long)param_2;
  local_50[1] = *(quad_t *)(long)(param_2 + 4);
  local_50[2] = *(quad_t *)(long)(param_2 + 8);
  local_50[3] = *(quad_t *)(long)(param_2 + 12);
  func_00142940(*(u32 *)(param_1 + 4), local_50);
  return;
}
