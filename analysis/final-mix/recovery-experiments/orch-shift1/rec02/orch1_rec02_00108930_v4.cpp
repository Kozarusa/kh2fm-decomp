#include "../common/types.h"

u32* func_00108930(u8* object, s32 index) {
    u32* head = *(u32**)(object + 0x2c);
    if (head != 0 && index >= 0 && index < 32) {
        u32* node = head;
        u32 flags = *node;
        if (flags != 0) {
            u32 mask = 1 << index;
            do {
                u32* result = node + 1;
                node += 2;
                if ((flags & mask) != 0) {
                    return result;
                }
                u32 next = *node;
                flags = next;
            } while (next != 0);
        }
    }
    return (u32*)(object + 4);
}
