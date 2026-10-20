#include "../common/types.h"

typedef void (*code)(void);

void func_001d2210(u32 *param_1)
{
  if ((param_1[3] & 4) != 0) {
    (*(code *)(*(u32 *)param_1 + 8))();
  }
}
