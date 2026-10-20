#include "../common/types.h"


typedef void (*code)(void);

void func_001d2210(u32 *param_1, u32 param_2, u32 param_3, u32 param_4)
{
  if (param_4 >= 4) {
    (*(code *)(*(u32 *)param_1 + 8))();
  }
  asm volatile ("");
}
