#include "../common/types.h"

extern "C" void func_0023acd8(int *);
extern "C" void func_0023ade0(int *);

void func_001ac310(int *param_1)
{
  int *puVar1;
  puVar1 = param_1 + 3;
  if (*param_1 != 0) {
    func_0023acd8(puVar1);
    puVar1[0x52] = param_1[1];
    puVar1[0x53] = param_1[2];
    func_0023ade0(puVar1);
    return;
  }
  return;
}