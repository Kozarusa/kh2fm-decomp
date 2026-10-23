#include "../common/types.h"

float func_002f8870(float param_1)
{
  unsigned int uVar1;
  __builtin_memcpy(&uVar1,&param_1,4);
  uVar1 &= 0x7fffffff;
  __builtin_memcpy(&param_1,&uVar1,4);
  return param_1;
}
