#include "../common/types.h"

extern "C" void func_0023acd8(...);
extern "C" void func_0023ade0(...);

void func_001ac310(s32 *param_1)
{
  if (*param_1 != 0) {
    func_0023acd8(param_1 + 3);
    param_1[0x55] = param_1[1];
    param_1[0x56] = param_1[2];
    func_0023ade0(param_1 + 3);
    return;
  }
  return;
}
