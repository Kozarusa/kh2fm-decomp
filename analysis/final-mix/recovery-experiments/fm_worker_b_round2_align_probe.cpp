#include "../common/types.h"

// Does a 16-byte-aligned type in the unit widen the callee-save slot stride?
extern "C" s32 func_003105a0(...);

// probe A: file-scope aligned static, never referenced
static char g_align16[16] __attribute__((aligned(16)));
u32 func_00309988(u32 param_1)
{
  u32 x1 = param_1;
  u32 x2 = param_1 + 1;
  asm("" : "+r"(x1), "+r"(x2));
  func_003105a0(x1);
  return x1 + x2;
}

// probe B: local with 16-byte alignment
struct __attribute__((aligned(16))) align16 { u32 a; u32 b; u32 c; u32 d; };
u32 func_003099c8(u32 param_1)
{
  struct align16 local_18;
  u32 x1 = param_1;
  u32 x2 = param_1 + 1;
  local_18.a = x1;
  asm("" : "+r"(x1), "+r"(x2));
  func_003105a0(x1);
  return x1 + x2 + local_18.a;
}

// probe C: typedef with 16-byte alignment used as a local
typedef u32 vec4 __attribute__((aligned(16)));
u32 func_00309a08(u32 param_1)
{
  vec4 local_18;
  u32 x1 = param_1;
  u32 x2 = param_1 + 1;
  local_18 = x1;
  asm("" : "+r"(x1), "+r"(x2));
  func_003105a0(x1);
  return x1 + x2 + local_18;
}

// probe D: aligned union type at file scope, referenced
union __attribute__((aligned(16))) align_u { double d; u32 w[4]; };
static union align_u g_union;
u32 func_00309a48(u32 param_1)
{
  u32 x1 = param_1;
  u32 x2 = param_1 + 1;
  g_union.w[0] = x1;
  asm("" : "+r"(x1), "+r"(x2));
  func_003105a0(x1);
  return x1 + x2 + g_union.w[0];
}

// probe E: array of doubles (8-byte aligned, 16-byte length)
u32 func_00309a88(u32 param_1)
{
  double local_18[2];
  u32 x1 = param_1;
  u32 x2 = param_1 + 1;
  local_18[0] = x1;
  asm("" : "+r"(x1), "+r"(x2));
  func_003105a0(x1);
  return x1 + x2 + (u32)local_18[0];
}

// probe F: control - no alignment anywhere
u32 func_00309ac8(u32 param_1)
{
  u32 x1 = param_1;
  u32 x2 = param_1 + 1;
  asm("" : "+r"(x1), "+r"(x2));
  func_003105a0(x1);
  return x1 + x2;
}
