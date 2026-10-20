#include "../common/types.h"

typedef void (*code)(void);

void func_002ecdb0(u32 param_1)
{
  code *pcVar1;
  pcVar1 = (code *)(*(u32 *)param_1 + 0x24);
  (*pcVar1)();
}
