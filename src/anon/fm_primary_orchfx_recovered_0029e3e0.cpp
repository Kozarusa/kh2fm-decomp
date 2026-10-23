#include "../common/types.h"

extern "C" s8 D_0035f228;
extern "C" s16 D_0035f5b6;
extern "C" void func_00292630();
extern "C" void func_0029e430();
extern "C" void func_00293c40(s32, s32);
extern "C" s32 func_002925c0();

s32 func_0029e3e0(s32 value)
{
  func_00292630();
  func_0029e430();
  D_0035f5b6 = value;
  func_00293c40((s16)value, D_0035f228 == 1);
  return func_002925c0();
}
