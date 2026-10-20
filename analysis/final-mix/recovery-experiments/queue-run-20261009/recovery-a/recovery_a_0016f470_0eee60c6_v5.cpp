#include "../common/types.h"
extern "C" u32 func_002fee78(...);
extern "C" char D_004f63b0;
extern "C" char D_0036c440;

s32 func_0016f470(int param_1,s32 param_2)

{
  if (param_2 == 0) {
    param_2 = (s32)(long)&D_004f63b0;
  }
  func_002fee78(param_2,(u32)(long)&D_0036c440,param_1 + 8);
  return param_2;
}
