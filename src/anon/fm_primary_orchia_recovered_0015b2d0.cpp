#include "../common/types.h"
extern "C" s32 D_0034aaac;
extern "C" u8* D_0034aaa4;
extern "C" u8* D_0034aaa8;
extern "C" s32 func_001492f8(s32);
extern "C" s32 func_00149300(s32);
extern "C" u32 func_0019f880(...);
extern "C" u32 func_0015aba8(u8*, s32, s32);
extern "C" u32 func_0015aa98(u8*, u32, s32, f32);

u32 func_0015b2d0() {
    s32 first = func_001492f8(D_0034aaac);
    s32 second = func_00149300(D_0034aaac);
    if (first == 0 || second == 0) {
        u32 place = func_0019f880(-1, -1);

                 return func_0015aa98(D_0034aaa8, place, 20, 120.0f);
    }
    return func_0015aba8(D_0034aaa4, first, second);
}
