#include "../common/types.h"

typedef struct { u64 q[2]; } __attribute__((aligned(16))) quad_t;

extern "C" void func_001902a8(u32, void *);
extern "C" void func_0018a970(void *);

void func_001906f0(u32 param_1, quad_t *param_2)
{
  quad_t local_38[3];
  quad_t *puVar1;
  *(u32 *)(long)((u8 *)local_38 + 12) = 0;
  func_001902a8(param_1, local_38);
  puVar1 = (quad_t *)(long)((u8 *)local_38 + 32);
  asm volatile ("");
  *puVar1 = *param_2;
  asm volatile ("" ::: "memory");
  func_0018a970(local_38);
  return;
}
