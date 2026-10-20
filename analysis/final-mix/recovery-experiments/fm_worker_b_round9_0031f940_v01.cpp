#include "../common/types.h"

typedef void (*code)(void);

void func_0031f940(u32 param_1)
{
  code *pcVar1;
  pcVar1 = (code *)(*(u32 *)(param_1 + 0x18) + 0x10);
  (*pcVar1)();
}
