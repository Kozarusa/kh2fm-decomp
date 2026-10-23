#include "../common/types.h"

typedef void (*code)(u32, u32, u32);

void func_002ead20(u32 param_1, u32 param_2)
{
  code *pcVar1;
  pcVar1 = (code *)(*(u32 *)param_1 + 0x24);
  (*pcVar1)(param_1, param_2, 0x2b);
}
