#include "../common/types.h"

float func_002f8870(float param_1)
{
  union { float f; unsigned int i; } uVar1;
  uVar1.f = param_1;
  uVar1.i = uVar1.i & 0x7fffffffu;
  asm("" : "+r"(uVar1.i));
  return uVar1.f;
}
