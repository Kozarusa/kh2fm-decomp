#include "../common/types.h"

typedef void (*code)(void);

u64 func_002b6ab8(void)
{
  u64 uVar1;
  uVar1 = 0;
  asm volatile("" : : "r"(&uVar1) : "memory");
  return uVar1;
}
