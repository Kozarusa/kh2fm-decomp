#include "../common/types.h"
extern "C" u32 func_00239bf8(s32, s32);

void func_001ac078(u8* object, s64 first, s32 second, s64 third) {
    s32 base;
    s32 value;
    object[0] = (u8)first;
    object[1] = (u8)second;
    base = ((s32)first * 4 + second) * 2;
    object[2] = (u8)third;
    value = base + 0x21;
    if (third < 4) {
        value = base + 0x25;
    }
    if (first != 0) {
        func_00239bf8((s32)(object + 4), value);
        return;
    }
}
