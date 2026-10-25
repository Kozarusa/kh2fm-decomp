#include "../common/types.h"
// why: copied from the accepted call site in fm_primary_capacity_recovered_00303c48.cpp; the varargs form changes codegen here (v2 with fixed parameters for this and func_001386e0 differed by 44 words, v1 with varargs is exact)
extern "C" int func_0023f1b0(...);
extern "C" u32 func_0023c4b8(u32, s32);
extern "C" s32 func_00236ca8(s32, s32);
// why: copied from the accepted call site in fm_primary_orchlg_recovered_00288670.cpp; the varargs form changes codegen here (v2 with u64 parameters differed by 44 words, v1 with varargs is exact)
extern "C" u32 func_001386e0(...);

// why: ruling #36 void: the only exit leaves the v0 of func_001386e0, whose own instructions never write v0 and which ends in a tail jump to func_001387f8, accepted as void (fm_primary_width_recovered_00.cpp), so the exit is stale-b

// Preserve original registry aliases.
void func_0028d8c0(u8* object, s32 kind, s32 sequence, s32 image, s32 layout, s32 first, s32 value, s32 second) asm("_ZN2Tz5Pause16CreateFadeObjectEz");

void func_0028d8c0(u8* object, s32 kind, s32 sequence, s32 image, s32 layout, s32 first, s32 value, s32 second) {
    u32 unit = func_0023c4b8(func_0023f1b0(layout), sequence);
    s32 picture = func_00236ca8(*(s32*)(func_0023f1b0(layout) + 40), image);
    func_001386e0(object, kind, unit, picture, first, second);
    *(s32*)(object + 392) = value;
}
