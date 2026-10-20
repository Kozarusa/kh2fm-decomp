#include "../common/types.h"

extern "C" void func_0023acd8(int *);
extern "C" void func_0023ade0(int *);

void func_001ac310(int *param_1)
{
  u8 *pbVar1;
  pbVar1 = (u8 *)(param_1 + 3);
  if (*param_1 != 0) {
    func_0023acd8(param_1 + 3);
    *(u8 *)(pbVar1 + 0x148) = (u8)param_1[1];
    *(u8 *)(pbVar1 + 0x14c) = (u8)param_1[2];
    func_0023ade0(param_1 + 3);
    return;
  }
  return;
}
