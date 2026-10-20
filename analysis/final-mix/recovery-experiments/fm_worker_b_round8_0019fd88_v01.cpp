#include "../common/types.h"

typedef void (*code)(void);

void func_0019fd88(u32 param_1)
{
  code *pcVar1;
  pcVar1 = (code *)(*(u32 *)param_1 + 0x24);
  (*pcVar1)(param_1, 0);
}
