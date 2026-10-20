#include "../common/types.h"

typedef void (*code)(u32);

void func_00185a68(u32 param_1)
{
  code *pcVar1;
  pcVar1 = (code *)(*(u32 *)(param_1 + 0x9f4) + 0x50);
  (*pcVar1)(param_1);
}
