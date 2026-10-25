#include "../common/types.h"
extern "C" f32 D_0036e0a8;
extern "C" u8* func_0017df58(s32);         // copied from accepted caller fm_primary_orchiv_recovered_001798d8.cpp
extern "C" s32 func_0019ba60(u8*);         // copied from accepted caller fm_primary_orchiv_recovered_001798d8.cpp
extern "C" u16 func_0016a070(u8*);         // copied from accepted caller fm_primary_orchcg_recovered_001b3a90.cpp
extern "C" s32 func_001c9958(u32, u32);
// why: types copied from accepted declaration u32 func_001c9780(u32, f32) in auto80_199_queue_decls.hpp (C++ linkage there), plus extern "C" for the isolated probe link
extern "C" u32 func_001c9780(u32, f32);

// why: s32, not void (DEVIATIONS #36 does not apply): the only exit leaves the direct result of the last call on each path (0019ba60, 001c9958 or 001c9780, which tail-chains into 001a8f10's s32)

s32 func_001c9860(u32 form) {
    s32 index = 0;
    s32 result;
    // why: goto loop keeps the loop optimizer from hoisting the float global's lui out of the loop
next:
    u8* member = func_0017df58(index);
    index++;
    result = func_0019ba60(member);
    if (result != 0) {
        result = func_001c9958(form, func_0016a070(member));
        f32* scale = &D_0036e0a8;
        asm("" : "+r"(scale)); // why: original materializes the full address (addiu) before the branch and loads with offset 0
        f32 value = *scale; // why: original loads the float in the branch delay slot, before the result test
        if (result != 0) {
            // why: the accepted declaration types the member argument as u32
            result = func_001c9780((u32)member, value);
        }
    }
    if (index < 2) goto next;
    return result;
}
