#include "../common/types.h"

u32* func_00108930(u8* object, s32 index) {
    u32* result = (u32*)(object + 4);
    u32* head = *(u32**)(object + 0x2c);
    if (head != 0 && index >= 0 && index < 32) {
        u32* node = head;
        u32 flags = *node;
        if (flags != 0) {
            u32 mask = 1 << index;
            do {
                result = node + 1;
                if ((flags & mask) != 0) {
                    return result;
                }
                node += 2;
                flags = *node;
            } while (flags != 0);
            result = (u32*)(object + 4);
        }
    }
    return result;
}
