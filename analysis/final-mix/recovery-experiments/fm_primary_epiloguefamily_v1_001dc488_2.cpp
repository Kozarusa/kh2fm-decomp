#include "../common/types.h"
extern "C" u32 D_01d6bb00;
typedef void (*code)(u32,u32,u32);
void func_001dc488(u32 param_1)
{
  (*(code *)(*(u32 *)D_01d6bb00))(D_01d6bb00, param_1, 0);
  asm volatile ("" ::: "memory");
}
