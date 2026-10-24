// func_0017f268: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" s32 func_0017ec98(void*, s32);
extern "C" u32 func_0017ebc8(...);
extern "C" u32 func_0017eda8(void*, s32);
extern "C" s32 func_0017f178(void*, s32, f32, f32);
extern "C" u32 func_0017f5e0(void*, s32, f32, f32, void*);
extern "C" bool func_001805a8(...);

s32 func_0017f268(u8* object, s32 index, f32 first, f32 second) {
    register s32 result asm("$15"); // why: original stages the return value in t7 before v0
    s32 motion = func_0017ec98(object, index);
    if (func_0017ebc8(object) != 0 && index == 0) {
        u32 status = func_0017eda8(object, motion);
        u32 state = *(u32*)(object + 0x1c);
        if (((state < 2 && status - 2 < 2) || (state - 2 < 2 && status < 2)) && func_001805a8(object, 6) != 0) {
            func_0017f268(object, 6, 0.0f, 0.0f);
            func_0017f5e0(object, 0, 0.0f, 0.0f, 0);
            result = 1;
            goto done;
        }
    }
    if (func_0017f178(object, motion, first, second) != 0) {
        *(s32*)(object + 0x14) = index;
        result = 1;
    } else {
        result = 0;
    }
done:
    return result;
}
