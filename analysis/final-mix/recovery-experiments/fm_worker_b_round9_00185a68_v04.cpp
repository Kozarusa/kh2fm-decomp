#include "../common/types.h"

typedef void (*code)(u32, u32, u32);

void func_00185a68(u32 param_1, u32 param_2, u32 param_3)
{
  (*(code *)(*(u32 *)(*(u32 *)(param_1 + 0x9f4) + 0x50)))(param_2, param_3, param_1);
  asm volatile ("");
}
