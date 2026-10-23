#include "../common/types.h"

extern "C" bool func_001c0cd8(s32);
u32 func_001943e8(s32 object);

u32 func_001943e8(s32 object) {
    f32* cursor = (f32*)(object + 0x30);
    s32 count = 2;
    u32 result = 0;
    do {
        f32 value = *cursor;
        cursor++;
        if (value < 0.0f) {
            result = result ^ 1;
        }
        count--;
    } while (count >= 0);
    if (func_001c0cd8(object)) {
        u32 other = func_001943e8(*(s32*)(object + 0x570));
        result = (result != other);
    }
    return result;
}
