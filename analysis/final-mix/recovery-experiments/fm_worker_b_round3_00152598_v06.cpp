#include "../common/types.h"

int func_00152598(int param_1,int param_2,long param_3,int param_4)
{
  int *puVar1 = (int *)(param_2 * 8 + param_4);
  if (param_3 == 0) {
    return puVar1[0];
  }
  return puVar1[1];
}
