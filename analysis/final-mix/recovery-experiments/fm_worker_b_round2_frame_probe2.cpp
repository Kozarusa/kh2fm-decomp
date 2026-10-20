#include "../common/types.h"

// Which construct forces 16-byte-spaced callee-save slots (s0@0, s1@16, ra@32)?
// Each slot is parked on an override range; only the compiled prologue matters.

// 1: variadic callee call
extern "C" s32 func_003105a0(...);
extern "C" s32 func_003105a1(...);
u32 func_00309988(u32 param_1)
{
  return func_003105a0(param_1) + func_003105a1();
}

// 2: call with 6 integer args (2 pushed on the stack)
extern "C" s32 func_003105b0(u32,u32,u32,u32,u32,u32);
u32 func_003099c8(u32 param_1)
{
  return func_003105b0(param_1,param_1,param_1,param_1,param_1,param_1);
}

// 3: 16-byte struct local
struct big16 { u32 a; u32 b; u32 c; u32 d; };
u32 func_00309a08(u32 param_1)
{
  struct big16 local_2c;
  local_2c.a = param_1;
  local_2c.b = 0;
  local_2c.c = 0;
  local_2c.d = 0;
  return local_2c.a + local_2c.b + local_2c.c + local_2c.d;
}

// 4: long long local
u32 func_00309a48(u32 param_1)
{
  long long local_18;
  local_18 = param_1;
  return (u32)(local_18 + 1);
}

// 5: callee taking a struct by value on the stack
struct oct8 { u32 a; u32 b; };
extern "C" s32 func_003105c0(u32,struct oct8);
u32 func_00309a88(u32 param_1)
{
  struct oct8 local_20;
  local_20.a = param_1;
  local_20.b = 0;
  return func_003105c0(param_1,local_20);
}

// 6: double parameter (incoming, unused)
extern "C" s32 func_003105d0(u32,double);
u32 func_00309ac8(u32 param_1,double param_2)
{
  return func_003105d0(param_1,param_2);
}

// 7: asm with memory clobber
u32 func_00309b08(u32 param_1)
{
  asm volatile("" : : : "memory");
  return param_1 + 1;
}

// 8: alloca
u32 func_00309b48(u32 param_1)
{
  u32 *local_18;
  local_18 = (u32 *)__builtin_alloca(8);
  *local_18 = param_1;
  return *local_18;
}
