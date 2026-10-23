#include "../common/types.h"

extern "C" void func_00103748(void);
extern "C" void func_00170c00(s64);
extern "C" s32 func_00103bb0(s32);
extern "C" s32 D_003638c4;
extern "C" u8 D_003638c0;
extern "C" u8 D_003638c8;

s32 func_002ef708(void)
{
  func_00103748();
  func_00170c00(D_003638c4);
  D_003638c4 = 0;
  s32 result = func_00103bb0(-1);
  D_003638c0 = 0;
  D_003638c8 = 0;
  return result;
}
