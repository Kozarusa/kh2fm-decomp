#include "../common/types.h"

typedef void (*code)(void);

void func_00171348(u32 *param_1)
{
  code *pcVar1;
  pcVar1 = (code *)(*(u32 *)(*(u32 *)*param_1 + 4) + 0x44);
  (*pcVar1)();
}
