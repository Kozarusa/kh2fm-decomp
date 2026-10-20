#include "../common/types.h"

// Frame-layout probes: which construct forces the 16-byte callee-save stride
// (frame 48, s0@0, s1@16, ra@32) seen in the 0x0030xxxx family?
// Each slot uses unique callee names (duplicate declarations of one name
// conflict, so probes must not share callee identities).

// slot 1: baseline (known-good body compiles to frame 32)
extern "C" bool func_0030edb0(...);
extern "C" bool func_0030ee00(...);
extern "C" s32 func_003105b0(...);
u32 func_00309988(u32 param_1)
{
  bool lVar1;
  u32 uVar2;
  lVar1 = func_0030edb0();
  uVar2 = func_003105b0(param_1);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}

// slot 2: non-variadic prototypes
extern "C" bool func_0030edb1(void);
extern "C" void func_0030ee01(void);
extern "C" s32 func_003105b1(u32);
u32 func_003099b8(u32 param_1)
{
  bool lVar1;
  u32 uVar2;
  lVar1 = func_0030edb1();
  uVar2 = func_003105b1(param_1);
  if (lVar1 != 0) {
    func_0030ee01();
  }
  return uVar2;
}

// slot 3: struct return of two words
struct probe_pair { u32 lo; u32 hi; };
extern "C" probe_pair func_0030edb2(void);
extern "C" void func_0030ee02(void);
extern "C" s32 func_003105b2(u32);
u32 func_003099e8(u32 param_1)
{
  probe_pair tmp;
  s32 uVar2;
  tmp = func_0030edb2();
  uVar2 = func_003105b2(param_1);
  if (tmp.lo != 0) {
    func_0030ee02();
  }
  return uVar2;
}

// slot 4: unused double parameter on the middle call
extern "C" bool func_0030edb3(void);
extern "C" void func_0030ee03(void);
extern "C" s32 func_003105b3(u32, double);
u32 func_00309a18(u32 param_1)
{
  bool lVar1;
  u32 uVar2;
  lVar1 = func_0030edb3();
  uVar2 = func_003105b3(param_1,0.0);
  if (lVar1 != 0) {
    func_0030ee03();
  }
  return uVar2;
}

// slot 5: unused long long parameter on the middle call
extern "C" bool func_0030edb4(void);
extern "C" void func_0030ee04(void);
extern "C" s32 func_003105b4(u32, long long);
u32 func_00309a48(u32 param_1)
{
  bool lVar1;
  u32 uVar2;
  lVar1 = func_0030edb4();
  uVar2 = func_003105b4(param_1,0);
  if (lVar1 != 0) {
    func_0030ee04();
  }
  return uVar2;
}

// slot 6: double local live across both calls
extern "C" bool func_0030edb5(void);
extern "C" void func_0030ee05(void);
extern "C" s32 func_003105b5(u32);
u32 func_00309a78(u32 param_1)
{
  bool lVar1;
  u32 uVar2;
  double d;
  lVar1 = func_0030edb5();
  d = param_1 * 2.5;
  uVar2 = func_003105b5(param_1);
  if (lVar1 != 0) {
    func_0030ee05();
  }
  if (d > 1.0) {
    uVar2 = uVar2 + 1;
  }
  return uVar2;
}

// slot 7: eight-byte struct local held across both calls
struct probe_pair2 { u32 lo; u32 hi; };
extern "C" bool func_0030edb6(probe_pair2 *);
extern "C" void func_0030ee06(void);
extern "C" s32 func_003105b6(u32);
u32 func_00309aa8(u32 param_1)
{
  probe_pair2 local_2c;
  bool lVar1;
  u32 uVar2;
  local_2c.lo = param_1;
  local_2c.hi = 0;
  lVar1 = func_0030edb6(&local_2c);
  uVar2 = func_003105b6(param_1);
  if (lVar1 != 0) {
    func_0030ee06();
  }
  return uVar2;
}
