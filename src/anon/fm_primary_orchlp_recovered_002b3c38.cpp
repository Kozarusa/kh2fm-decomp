#include "../common/types.h"
extern "C" u8* D_0035f638;
extern "C" s32 func_002a9d68(void);
// why: the recovered call site in fm_primary_orchjp_recovered_002b1aa0.cpp uses a variadic form; here the single argument (a0 = -1) is written as a fixed s32 parameter
extern "C" u32 func_002b23e0(s32);
// why: no recovered declaration; a0 and a1 are sign-extended halfwords (lh) and v0 is used as an index
extern "C" s32 func_002b2380(s32, s32);

// why: every exit returns a value the function computes itself (move v0,s4 with s4 = 1 or the sign flag of a loaded byte), an own value

s32 func_002b3c38(u32 flags) {
    u8* first = (u8*)func_002b23e0(-1);
    s32 result = 1;
    u8* sram = (u8*)func_002a9d68();
    s16* halves = (s16*)D_0035f638;
    u32 side = (*(u32*)(D_0035f638 + 52) >> 11) & 1;
    s32 index = func_002b2380(halves[side + 14], halves[side + 16]);
    s8 value = *(s8*)(sram + (first[2] * 48 + index) * 4 + 488);
    if ((flags & 0xc0004) != 0) {
        if ((*(u32*)(D_0035f638 + 52) & 0x800) == 0) {
            result = value >= 0;
        }
    }
    return result;
}
