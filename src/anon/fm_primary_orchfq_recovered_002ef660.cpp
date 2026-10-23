#include "../common/types.h"
extern "C" u32 func_0023a918(s32);

u8* func_002ef660(u8* destination, s32 source) {
    u32 value = func_0023a918(source + 0x1d4);
    *destination = (u8)value;
    destination[1] = (u8)(value >> 8);
    destination[2] = (u8)(value >> 0x10);
    destination[3] = (u8)(value >> 0x18);
    return destination;
}
