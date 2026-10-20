#include "../common/types.h"

extern "C" char *func_002424c0(...);
extern "C" char *func_001058e8(...);

s32 func_00242500(s32 param_1)
{
  s32 iVar1;
  char *puVar1;
  char *puVar2;
  puVar2 = func_002424c0();
  if (puVar2 != 0) {
    puVar1 = func_001058e8();
    iVar1 = *(int *)(puVar1 + 0x2440) + param_1;
  }
  else {
    puVar1 = func_001058e8();
    iVar1 = 999999;
  }
  *(int *)(puVar1 + 0x2440) = iVar1;
  puVar1 = func_001058e8();
  return *(int *)(puVar1 + 0x2440);
}
