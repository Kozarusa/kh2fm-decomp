#include "../common/types.h"

extern "C" u32 func_002dc7c8(...);

f32 func_002dc808(s32 object) {
    f32 result;
    register u8 *base asm("$15") = (u8 *)object + 0x8000; // why: original addresses the flag through t7
    register s32 flag asm("$13") = *(s32 *)(base + 0x70); // why: original loads the flag into t5
    if (flag != 0) {
        s32 table = func_002dc7c8();
        result = *(f32 *)(table + 0xb4);
    } else {
        f32 *slot = (f32 *)func_002dc7c8();
        result = *slot;
    }
    return result;
}
