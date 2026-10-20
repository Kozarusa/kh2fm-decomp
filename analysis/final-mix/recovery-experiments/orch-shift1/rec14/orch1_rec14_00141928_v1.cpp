#include "../common/types.h"

void func_00141928(u8* object, u8 id) {
    s32 count = *(s32*)(object + 0x24);
    if (count > 0) {
        s32 offset = 0;
        do {
            u8* entry = *(u8**)(object + 8) + offset;
            offset += 20;
            if (entry[17] == id) {
                entry[16] = 1;
            }
            count--;
        } while (count != 0);
    }
}
