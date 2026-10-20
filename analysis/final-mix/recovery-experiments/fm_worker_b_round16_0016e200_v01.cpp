#include "../common/types.h"

typedef struct __attribute__((aligned(16))) {
  u64 field_0;
  u64 field_1;
} quad;

extern "C" quad *func_001dc648(u32);

void func_0016e200(u32 *param_1)
{
  quad *puVar1;
  quad *puVar2;
  puVar2 = (quad *)func_001dc648(*param_1);
  puVar1 = (quad *)param_1[1];
  if (puVar2 != puVar1) {
    *puVar2 = *puVar1;
  }
  return;
}
