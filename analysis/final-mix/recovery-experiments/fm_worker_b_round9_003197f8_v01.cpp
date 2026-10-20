#include "../common/types.h"

typedef void (*code)(void);

void func_003197f8(u32 param_1)
{
  code *pcVar1;
  pcVar1 = (code *)(*(u32 *)(param_1 + 4) + 4);
  (*pcVar1)();
}
