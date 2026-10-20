#include "../common/types.h"
extern "C" u8 D_0032fb68[];

u32 func_001b8d60(u8* destination) {
    s32 index = 0;
    u8* base = D_0032fb68;
    u32 count = base[287];
    base[287] = 0;
    if (count != 0) {
        u8* source = base;
        do {
            u8 byte = source[index + 32];
            u8* target = destination + index;
            index++;
            *target = byte;
        } while (index < (s32)count);
    }
    return count;
}
