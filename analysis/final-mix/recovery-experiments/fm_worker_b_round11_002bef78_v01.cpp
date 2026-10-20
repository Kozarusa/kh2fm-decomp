#include "../common/types.h"

typedef void (*code)(void);

void func_002bef78(u32 param_1, u64 param_2, u32 param_3)
{
  volatile u64 local_1;
  volatile u32 local_2;
  local_1 = param_2;
  local_2 = param_3;
  param_1 = *(u32 *)(param_1 + 36);
  (*(code *)(*(u32 *)param_1 + 0x10))();
  asm volatile ("");
}
