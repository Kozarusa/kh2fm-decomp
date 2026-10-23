#include "../common/types.h"

void func_002e9fb8(u8* object, u8 flag) {
    u32 bit = (u32)(flag > 0);
    *(u32*)(object + 4) = (*(u32*)(object + 4) & 0xfffeffff) | (bit << 16);
}
