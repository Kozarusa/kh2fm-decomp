#include "../common/types.h"

void func_001db850(u8* object) {
    s32 count = *(s32*)(object + 0x18);
    s32 index = 0;
    if (0 < count) {
        s32* base = *(s32**)(object + 0x10);
        while (true) {
            base[index] = index;
            count = *(s32*)(object + 0x18);
            index = index + 1;
            if (count <= index) break;
            base = *(s32**)(object + 0x10);
        }
    }
    *(s32*)(object + 8) = count;
}
