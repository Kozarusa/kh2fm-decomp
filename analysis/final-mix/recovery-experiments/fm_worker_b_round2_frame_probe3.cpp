#include "../common/types.h"

// Frame-stride experiment for func_00310620: the original allocates three
// 16-byte save slots (frame 48: s0@0, s1@16, ra@32) while the pinned compiler
// emits three 8-byte slots. Probe constructs that could leave dead 8-byte
// stack slots interleaved with the register saves.

extern "C" bool func_0030edb0(...);
extern "C" bool func_0030ee00(...);
extern "C" s32 func_003105b0(...);

// 1: two dead scalar locals
u32 func_00309988(u32 param_1)
{
  u32 dead1;
  u32 dead2;
  bool lVar1;
  u32 uVar2;
  dead1 = param_1;
  dead2 = param_1 + 1;
  lVar1 = func_0030edb0();
  uVar2 = func_003105b0(param_1);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}

// 2: one dead long long local
u32 func_003099c8(u32 param_1)
{
  long long dead1;
  bool lVar1;
  u32 uVar2;
  dead1 = param_1;
  lVar1 = func_0030edb0();
  uVar2 = func_003105b0(param_1);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}

// 3: dead double locals
u32 func_00309a08(u32 param_1)
{
  double dead1;
  double dead2;
  bool lVar1;
  u32 uVar2;
  dead1 = param_1;
  dead2 = param_1 + 1;
  lVar1 = func_0030edb0();
  uVar2 = func_003105b0(param_1);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}

// 4: dead struct local
struct pair { u32 lo; u32 hi; };
u32 func_00309a48(u32 param_1)
{
  struct pair dead1;
  bool lVar1;
  u32 uVar2;
  dead1.lo = param_1;
  dead1.hi = 0;
  lVar1 = func_0030edb0();
  uVar2 = func_003105b0(param_1);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}

// 5: unused locals never assigned
u32 func_00309a88(u32 param_1)
{
  u32 dead1;
  u32 dead2;
  bool lVar1;
  u32 uVar2;
  lVar1 = func_0030edb0();
  uVar2 = func_003105b0(param_1);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}

// 6: dead local written through a pointer
u32 func_00309ac8(u32 param_1)
{
  u32 *dead1;
  bool lVar1;
  u32 uVar2;
  dead1 = &param_1;
  *dead1 = 0;
  lVar1 = func_0030edb0();
  uVar2 = func_003105b0(param_1);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}

// 7: dead local inside the branch
u32 func_00309b08(u32 param_1)
{
  bool lVar1;
  u32 uVar2;
  u32 dead1;
  lVar1 = func_0030edb0();
  uVar2 = func_003105b0(param_1);
  if (lVar1 != 0) {
    dead1 = param_1;
    func_0030ee00();
  }
  return uVar2;
}

// 8: control, no dead locals
u32 func_00309b48(u32 param_1)
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
