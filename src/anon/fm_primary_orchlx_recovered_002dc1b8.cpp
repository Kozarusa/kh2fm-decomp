#include "../common/types.h"
extern "C" bool func_001c0cd8(s32);                         // copied from accepted caller fm_primary_fiveword_recovered_0016fa58.cpp
extern "C" void func_001dc818(s32);                         // void as in the recovered named-module declaration ryj_EFFECT_loop_end in src/ys/traps.cpp; the fiveword placeholder callers declare u32
extern "C" u32 func_0016ac38(s64, u64, u64, u64, s64);      // parameters copied from accepted caller fm_primary_fiveword_recovered_0017a8f8.cpp; result type u32 because the original stores v0 with a plain sw (the u64 result declared there added dsll32/dsra32, measured in v1: 11 words)

// Exits (ruling #36 used): early return after the equal-index check = direct result of func_001c0cd8 (bool); fall-through after func_001dc818 with a negative index = stale-b (func_001dc818 is void in src/ys/traps.cpp); fall-through after func_0016ac38 = direct (stored, then left in v0). Direct exits coexist with the stale-b exit, so void is allowed.

void func_002dc1b8(u8* object, s32 index) {
    if (func_001c0cd8((s32)object) || object[0xbc0] != 0) {
        index = -1;
    }
    s32 effect = *(s32*)(object + 0xb0c);
    if (effect != 0) {
        if (*(s32*)(object + 0xb14) == index) {
            return;
        }
        func_001dc818(effect);
        *(s32*)(object + 0xb0c) = 0;
    }
    if (index >= 0) {
        *(s32*)(object + 0xb0c) = func_0016ac38((s64)object, index, 1, 0, 0);
    }
    *(s32*)(object + 0xb14) = index;
}
