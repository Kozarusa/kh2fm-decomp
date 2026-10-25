#include "../common/types.h"
extern "C" u32 D_0035f010;
extern "C" s32 func_00257070(s32);
// why: a0 is the party info pointer word loaded from D_0035f010, v0 is compared as a signed count
extern "C" s32 func_00281100(u32);
// why: a0 = 25, a1 = position, a2 = 0
extern "C" void func_00257050(s32, s32, s32);
// why: a0 is the party info word, a1 the position; v0 is passed on as a message pointer
extern "C" u32 func_00281140(u32, s32);
// why: a0 = 1, a1 = the name returned by func_00281140
extern "C" u64 func_0028fb68(s32, u32);

// Preserve original registry aliases.
s32 func_00273de0(u8 forward, u8 show) asm("_ZN2Tz6Jiminy4InitEv");

s32 func_00273de0(u8 forward, u8 show) {
    s32 position = func_00257070(25);
    s32 count = func_00281100(D_0035f010);
    if (forward) {
        position++;
        if (position >= count) {
            position = 0;
        }
    } else {
        position--;
        if (position < 0) {
            position = count - 1;
        }
    }
    if (show) {
        func_00257050(25, position, 0);
        func_0028fb68(1, func_00281140(D_0035f010, position));
    }
    return position;
}
