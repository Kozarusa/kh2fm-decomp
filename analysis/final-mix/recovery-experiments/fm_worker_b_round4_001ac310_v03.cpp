#include "../common/types.h"

extern "C" void func_0023acd8(int *);
extern "C" void func_0023ade0(int *);

void func_001ac310(int *param_1)
{
  int *puVar1;
  int iVar2;
  int iVar3;
  puVar1 = param_1 + 3;
  iVar3 = param_1[2];
  iVar2 = param_1[1];
  if (*param_1 != 0) {
    func_0023acd8(puVar1);
    puVar1[0x52] = iVar2;
    puVar1[0x53] = iVar3;
    func_0023ade0(puVar1);
    return;
  }
  return;
}
