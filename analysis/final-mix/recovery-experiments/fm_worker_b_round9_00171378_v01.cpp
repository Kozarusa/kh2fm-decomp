#include "../common/types.h"

typedef void (*code)(void);

void func_00171378(u32 *param_1)
{
  code *pcVar1;
  pcVar1 = (code *)(*(u32 *)(*(u32 *)*param_1 + 4) + 0x48);
  (*pcVar1)();
}
