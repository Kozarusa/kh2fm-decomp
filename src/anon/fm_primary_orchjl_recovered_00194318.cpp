#include "../common/types.h"
extern "C" u8* func_001bfd60(...);

u8* func_00194318(u8* object) {
    s32 step = (object[0x8dc] == 1) ? -16 : 16;
    s32 level = object[0x8dd] + step;
    s32 clamped;
    if (level >= 0) {
        if (level < 129) {
            clamped = level;
        } else {
            clamped = 128;
        }
    } else {
        clamped = 0;
    }
    object[0x8dd] = clamped;
    u8* first = func_001bfd60(object + 0x8e0, 0xffc00);
    u8* second = func_001bfd60(object + 0x8e0, 0x3ff00000);
    *(u32*)(object + 0x678) |= 0x10;
    u8 value = object[0x8dd];
    if (value < 64) {
        first[7] = 0x80;
        second[7] = object[0x8dd] << 1;
    } else {
        first[7] = -(value << 1);
        second[7] = 0x80;
    }
    return second;
}
