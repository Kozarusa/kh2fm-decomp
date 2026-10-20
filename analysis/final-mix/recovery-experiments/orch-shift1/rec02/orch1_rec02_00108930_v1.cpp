#include "../common/types.h"

u32* func_00108930(u8* object, s32 index) {
    u32* node = *(u32**)(object + 0x2c);
    if (node != 0 && index >= 0 && index < 32) {
        u32 flags = *node;
        while (flags != 0) {
            u32* result = node + 1;
            node = node + 2;
            if ((flags & (1 << index)) != 0) {
                return result;
            }
            flags = *node;
        }
    }
    return (u32*)(object + 4);
}
