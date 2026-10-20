#include "../common/types.h"

typedef void (*code)(void);

void func_00322968(u32 param_1)
{
  u32 iVar1;
  code *pcVar1;
  iVar1 = *(u32 *)param_1;
  asm volatile("" : "+r"(iVar1));
  pcVar1 = (code *)(iVar1 + 0x14);
  (*pcVar1)();
}
