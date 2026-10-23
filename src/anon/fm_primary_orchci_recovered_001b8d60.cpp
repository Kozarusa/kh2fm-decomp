#include "../common/types.h"
extern "C" u8 D_0032fb68[];

u32 func_001b8d60(u8* destination) {
    u32 index = 0;
    u8* base = D_0032fb68;
    u32 count = base[287];
    base[287] = 0;
    if (count != 0) {
        u8* source = base;
        do {
            u8 byte = *(u8*)(index + (u32)source + 32);
            u8* target = destination + index;
            index++;
            *target = byte;
        } while ((s32)index < (s32)count);
    }
    return count;
}
