#include "../common/types.h"

float func_002f8870(float param_1)
{
  union { float f; unsigned int i; } uVar1;
  uVar1.i = *(unsigned int *)&param_1;
  uVar1.i &= 0x7fffffff;
  return uVar1.f;
}
