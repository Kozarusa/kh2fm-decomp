#include "../common/types.h"

typedef void (*code)(void);

void func_002ecdb0(u32 param_1)
{
  u32 iVar1;
  code pcVar2;
  __asm__ volatile("" : "=r"(iVar1) : "r"(*(u32 *)param_1));
  pcVar2 = *(code *)(iVar1 + 0x24);
  __asm__ volatile("" : "=r"(pcVar2) : "0"(*(code *)(iVar1 + 0x24)));
  pcVar2();
}
