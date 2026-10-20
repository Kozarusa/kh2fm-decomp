#include "../common/types.h"

typedef struct { u64 q[2]; } __attribute__((aligned(16))) quad_t;
typedef struct { quad_t q[4]; } __attribute__((aligned(16))) quad4_t;

extern "C" void func_00142940(u32, void *);

void func_00165830(u32 param_1, u32 *param_2)
{
  quad4_t local_50;
  local_50 = *(quad4_t *)(long)param_2;
  func_00142940(*(u32 *)(param_1 + 4), local_50);
  return;
}
