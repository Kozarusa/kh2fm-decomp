#include "../common/types.h"
extern "C" bool func_001c0cd8(s32);
extern "C" void func_0017f488(u8*, s32, f32, f32);
extern "C" void func_00180378(u8*, u8*, s32, f32);

// why: void per ruling #36: exits are entry v0 / stale (func_0017f488 result crossed later calls) / tail into func_00180378 (stale-b)

void func_002da958(u8* object) {
    u8* first = *(u8**)(object + 0xbf4);
    if (first != 0) {
        func_0017f488(first + 0x140, 0xad, 8.0f, 0.0f);
    }
    u8* second = *(u8**)(object + 0xbf0);
    if (second != 0) {
        if (func_001c0cd8((s32)second)) {
            func_0017f488(*(u8**)(object + 0xbf0) + 0x140, 0xad, 8.0f, 0.0f);
        }
        func_00180378(*(u8**)(object + 0xbf0) + 0x140, object, 0xfe, 8.0f);
    }
}
