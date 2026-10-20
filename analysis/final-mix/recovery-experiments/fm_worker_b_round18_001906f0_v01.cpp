#include "../common/types.h"

typedef struct { u64 q[2]; } __attribute__((aligned(16))) quad_t;

extern "C" void func_001902a8(u32, void *);
extern "C" void func_0018a970(void *);

void func_001906f0(u32 param_1, u32 *param_2)
{
  quad_t local_40[2];
  func_001902a8(param_1, local_40);
  *(u32 *)(local_40 + 1) = 0;
  *(u64 *)(long)(local_40 + 2) = *(u64 *)(long)param_2;
  func_0018a970(local_40);
  return;
}
