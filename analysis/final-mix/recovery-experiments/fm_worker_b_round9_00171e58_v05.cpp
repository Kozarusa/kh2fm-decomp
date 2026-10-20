#include "../common/types.h"

typedef void (*code)(void);

void func_00171e58(u32 param_1)
{
  (*(code *)(*(u32 *)(*(u32 *)(*(u32 *)param_1 + 4) + 0x20)))();
  asm volatile ("");
}
