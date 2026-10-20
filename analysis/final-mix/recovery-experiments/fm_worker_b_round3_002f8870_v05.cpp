#include "../common/types.h"

float func_002f8870(float param_1)
{
  unsigned int uVar1;
  union { float f; unsigned int i; } uVar2;
  uVar2.f = param_1;
  uVar1 = uVar2.i & 0x7fffffff;
  uVar2.i = uVar1;
  return uVar2.f;
}
