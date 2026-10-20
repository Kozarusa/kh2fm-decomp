#include "../common/types.h"

extern "C" void func_0023acd8(...);
extern "C" void func_0023ade0(...);

void func_001ac310(s32 *param_1)
{
  s32 *puVar1;
  if (*param_1 != 0) {
    puVar1 = param_1 + 3;
    func_0023acd8(puVar1);
    puVar1[0x52] = param_1[1];
    puVar1[0x53] = param_1[2];
    func_0023ade0(puVar1);
    return;
  }
  return;
}
