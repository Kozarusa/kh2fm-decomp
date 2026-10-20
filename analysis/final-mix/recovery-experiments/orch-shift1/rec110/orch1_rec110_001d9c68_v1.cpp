#include "../common/types.h"

u32 func_001d9c68(u8* data) {
    s32 index = 0;
    u8* pointer = data;
    do {
        u32 value = *pointer;
        index = index + 1;
        if (value != 1) {
            return 0;
        }
        pointer = data + index;
    } while (index < 5);
    return 1;
}
