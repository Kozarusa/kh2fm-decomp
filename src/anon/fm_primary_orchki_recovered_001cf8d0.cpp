#include "../common/types.h"
// why: void, as in the accepted definition fm_primary_queuedelta_recovered_001d86a0.cpp
extern "C" void func_001d86a0(u32, u32);
// why: void, as in the recovered definition void func_001d8820(u32)
extern "C" void func_001d8820(u32);
extern "C" void func_0017f488(u8*, s32, f32, f32);
extern "C" s32 func_0017f5e0(u8*, s32, s32, f32, f32);

// why: void under the second mixed-exit ruling (the default exit leaves the caller's v0 untouched, both case exits end in the final call into func_0017f5e0; same contract as accepted func_001c38c0)

void func_001cf8d0(u8* object, u8* event) {
    f32 zero;
    switch (*(u16*)(event + 2)) {
    case 411: {
        zero = 0.0f;
        func_001d86a0(-1, 1);
        u8* motion = object + 320;
        func_0017f488(motion, 201, zero, zero);
        func_0017f5e0(motion, 0, 0, zero, zero);
        break;
    }
    case 412: {
        zero = 0.0f;
        func_001d8820(1);
        u8* motion = object + 320;
        func_0017f488(motion, 161, zero, zero);
        func_0017f5e0(motion, 0, 0, zero, zero);
        break;
    }
    default:
        return;
    }
}
