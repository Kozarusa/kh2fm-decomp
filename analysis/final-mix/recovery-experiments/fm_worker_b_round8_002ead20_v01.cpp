#include "../common/types.h"


void func_002ead20(u32 param_1)
{
  code *pcVar1;
  pcVar1 = (code *)(*(u32 *)(param_1) + 0x24);
  (*pcVar1)(param_1, 0x2b);
}
