#include "../common/types.h"
extern "C" s32 D_0032dfc8;
extern "C" bool func_0019ba60(...);

s32 func_001a2108(u8* object, s32 value, u8* other) {
    s32 rate;
    s32 alternate;
    if (value <= 0) {
        return value;
    }
    if (!func_0019ba60(*(u8**)(object + 0x25c))) {
        return value;
    }
    switch (D_0032dfc8) {
    case 0:
        rate = 50;
        alternate = 150;
        break;
    case 2:
        rate = 200;
        alternate = 100;
        break;
    case 3:
        rate = 200;
        alternate = 125;
        break;
    default:
        return value;
    }
    if ((*(u32*)(*(u8**)(object + 0x25c) + 0x588) & 4) != 0) {
        value = (value * rate + 99) / 100;
    } else if (func_0019ba60(other) && (*(u32*)(other + 0x588) & 4) != 0) {
        value = (value * alternate + 99) / 100;
    }
    return value;
}
