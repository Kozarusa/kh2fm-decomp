#include "../common/types.h"
extern "C" bool func_00186ce8(...);
extern "C" bool func_00186d18(...);

bool func_00187e58(u8* object) {
    u32 bits;
    u8 flag;
    bits = *(u32*)(object + 0x9c);
    flag = bits & 1;
    if (flag) {
        return 0;
    }
    if ((*(u32*)(*(u8**)(*(u8**)(object + 0x88) + 4) + 0x588) & 2) &&
        (func_00186ce8(*(u8**)(*(u8**)(object + 0x88) + 4)) ||
         func_00186d18(*(u8**)(*(u8**)(object + 0x88) + 4)))) {
        return 1;
    }
    if (*(u32*)(*(u8**)(*(u8**)(object + 0x88) + 4) + 0x588) & 8) {
        return *(s32*)(*(u8**)(*(u8**)(object + 0x88) + 4) + 0x154) == 0x32;
    }
    return 0;
}
