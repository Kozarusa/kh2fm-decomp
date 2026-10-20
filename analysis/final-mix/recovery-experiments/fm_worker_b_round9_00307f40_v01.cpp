#include "../common/types.h"

extern "C" void func_00306e80(s32);

s32 func_00307f40(s64 param_1, s64 param_2, s32 param_3)
{
  if (param_3 != 0) {
    func_00306e80(param_3);
  }
  return 1;
}
