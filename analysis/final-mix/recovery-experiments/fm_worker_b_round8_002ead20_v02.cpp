#include "../common/types.h"

typedef void (*code)(u32, s32);

void func_002ead20(u32 param_1)
{
  code *pcVar1;
  pcVar1 = (code *)(*(u32 *)param_1 + 0x24);
  (*pcVar1)(param_1, 0x2b);
}
