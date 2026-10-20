#include "../common/types.h"

u32 func_001d9c68(u8* data) {
    s32 index = 0;
    do {
        if (data[index++] != 1) {
            return 0;
        }
    } while (index < 5);
    return 1;
}
