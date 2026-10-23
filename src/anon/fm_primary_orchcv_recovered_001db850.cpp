#include "../common/types.h"

void func_001db850(u8* object) {
    s32 count = *(s32*)(object + 0x18);
    s32 index = 0;
    if (0 < count) {
        register s32 base asm("$15") = *(s32*)(object + 0x10); // why: original keeps the array base in t7
        while (true) {
            *(s32*)(index * 4 + base) = index;
            count = *(s32*)(object + 0x18);
            index = index + 1;
            if (count <= index) break;
            base = *(s32*)(object + 0x10);
        }
    }
    *(s32*)(object + 8) = count;
}
