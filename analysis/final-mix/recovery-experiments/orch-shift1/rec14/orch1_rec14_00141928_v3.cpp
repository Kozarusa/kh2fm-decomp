#include "../common/types.h"

void func_00141928(u8* object, u8 id) {
    s32 total = *(s32*)(object + 0x24);
    if (total > 0) {
        s32 count = total;
        s32 offset = 0;
        do {
            u8* entry = offset + *(u8**)(object + 8);
            offset += 20;
            if (entry[17] == id) {
                entry[16] = 1;
            }
            count--;
        } while (count != 0);
    }
}
