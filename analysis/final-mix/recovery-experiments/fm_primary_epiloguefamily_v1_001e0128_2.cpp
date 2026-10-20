#include "../common/types.h"
extern "C" u32 D_01dae340;
typedef void (*code)(u32,u32,u32);
void func_001e0128(u32 param_1)
{
  (*(code *)(*(u32 *)D_01dae340))(D_01dae340, param_1, 0);
  asm volatile ("" ::: "memory");
}
