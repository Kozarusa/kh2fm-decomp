#include "../common/types.h"
extern "C" void func_002cd878(f32);

// Preserve original registry aliases.
u32 func_002cd910(f32 value, u32 object) asm("_Z13func_002cd910f");

u32 func_002cd910(f32 value, u32 object) {
    register s32 whole asm("$6") = (s32)value; // why: original keeps the truncated integer in a2
    func_002cd878(value - (f32)whole);
    return object;
}
