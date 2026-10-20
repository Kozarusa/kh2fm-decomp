#include "../common/types.h"
extern "C" u32 func_002fee78(...);
extern "C" char D_004f63b0;
extern "C" char D_0036c440;

s64 func_0016f470(int param_1,s64 param_2)

{
  if (param_2 == 0) {
    param_2 = (s64)(long)&D_004f63b0;
  }
  func_002fee78(param_2,(u32)(long)&D_0036c440,param_1 + 8);
  return param_2;
}
