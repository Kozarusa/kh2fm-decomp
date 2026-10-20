#include "../common/types.h"

typedef void (*code)(void);

void func_00185a98(u32 param_1)
{
  code *pcVar1;
  pcVar1 = (code *)(*(u32 *)(param_1 + 0x9f4) + 0x4c);
  (*pcVar1)();
}
