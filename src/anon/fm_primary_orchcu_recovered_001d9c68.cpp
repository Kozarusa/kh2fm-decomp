#include "../common/types.h"

u32 func_001d9c68(u8* data) {
    s32 index = 0;
    // why: original keeps the element address in t6 ($14) and the loaded byte in t7
    register u8* pointer asm("$14");
    do {
        pointer = data + index;
        index++;
        if (*pointer != 1) {
            return 0;
        }
    } while (index < 5);
    return 1;
}
