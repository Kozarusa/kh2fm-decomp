#include "../common/types.h"

typedef struct {
  u64 field_0;
  u64 field_1;
} quad;

extern "C" u32 func_0016c028(u32);

u32 func_0018d808(u32 param_1, u32 param_2)
{
  quad *puVar1;
  puVar1 = (quad *)func_0016c028(*(u32 *)(param_2 + 8));
  *(quad *)param_1 = *puVar1;
  return param_1;
}
