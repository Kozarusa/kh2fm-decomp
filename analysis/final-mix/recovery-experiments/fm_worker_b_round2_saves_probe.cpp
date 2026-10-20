#include "../common/types.h"

// Does the callee-save slot stride depend on how many registers are saved?
// Each probe keeps N values live across a call.
extern "C" s32 func_003105a0(...);
extern "C" s32 func_003105a1(...);
extern "C" s32 func_003105a2(...);
extern "C" s32 func_003105a3(...);
extern "C" s32 func_003105a4(...);
extern "C" s32 func_003105a5(...);

u32 func_00309988(u32 param_1)
{
  u32 x1 = param_1 + 1;
  asm("" : "+r"(x1));
  func_003105a0(x1);
  return x1;
}

u32 func_003099c8(u32 param_1)
{
  u32 x1 = param_1 + 1;
  u32 x2 = param_1 + 2;
  asm("" : "+r"(x1), "+r"(x2));
  func_003105a1(x1);
  return x1 + x2;
}

u32 func_00309a08(u32 param_1)
{
  u32 x1 = param_1 + 1;
  u32 x2 = param_1 + 2;
  u32 x3 = param_1 + 3;
  asm("" : "+r"(x1), "+r"(x2), "+r"(x3));
  func_003105a2(x1);
  return x1 + x2 + x3;
}

u32 func_00309a48(u32 param_1)
{
  u32 x1 = param_1 + 1;
  u32 x2 = param_1 + 2;
  u32 x3 = param_1 + 3;
  u32 x4 = param_1 + 4;
  asm("" : "+r"(x1), "+r"(x2), "+r"(x3), "+r"(x4));
  func_003105a3(x1);
  return x1 + x2 + x3 + x4;
}

u32 func_00309a88(u32 param_1)
{
  u32 x1 = param_1 + 1;
  u32 x2 = param_1 + 2;
  u32 x3 = param_1 + 3;
  u32 x4 = param_1 + 4;
  u32 x5 = param_1 + 5;
  asm("" : "+r"(x1), "+r"(x2), "+r"(x3), "+r"(x4), "+r"(x5));
  func_003105a4(x1);
  return x1 + x2 + x3 + x4 + x5;
}

u32 func_00309ac8(u32 param_1)
{
  u32 x1 = param_1 + 1;
  u32 x2 = param_1 + 2;
  u32 x3 = param_1 + 3;
  u32 x4 = param_1 + 4;
  u32 x5 = param_1 + 5;
  u32 x6 = param_1 + 6;
  asm("" : "+r"(x1), "+r"(x2), "+r"(x3), "+r"(x4), "+r"(x5), "+r"(x6));
  func_003105a5(x1);
  return x1 + x2 + x3 + x4 + x5 + x6;
}
