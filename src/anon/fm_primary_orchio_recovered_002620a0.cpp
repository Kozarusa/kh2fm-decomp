// func_002620a0: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" u32 func_00257770(void);
extern "C" u32 func_00287bc0(void);
extern "C" u32 func_0028dac8(...);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_0028acb8(u32);
extern "C" u32 func_0028aa40(u32);
extern "C" u32 D_0035f01c;

// Preserve original registry aliases.
u32 func_002620a0() asm("_ZN2Tz6CmItem10FadeOutTopEv");

u32 func_002620a0() {
    u32 object = func_00257770();
    u32 result = func_00287bc0();
    if (result == 0x1) {
        func_0028dac8(object,142);
        result = func_0028acc8(D_0035f01c);
        if (result) {
            result = func_0028acb8(D_0035f01c);
            if (!result) return func_0028aa40(D_0035f01c);
        }
    }
    return result;
}
