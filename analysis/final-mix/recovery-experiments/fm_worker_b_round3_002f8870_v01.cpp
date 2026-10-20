#include "../common/types.h"

float func_002f8870(float param_1)
{
  union { float f; int i; } uVar1;
  uVar1.f = param_1;
  uVar1.i &= 0x7fffffff;
  return uVar1.f;
}
