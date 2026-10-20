#include "../common/types.h"
extern "C" u32 func_00294000(u32);
u32 func_002953c8(s32 value) {
    u32 object = func_00294000(0);
    s32 count = *(s32*)(object + 8);
    u32 base = object + 16;
    u32 index = 0;
    register u32 offset asm("$2") = 0; // why: original offset uses v0
    if (count > 0) {
        do {
            offset = index << 4;
            ++index;
            if (*(s8*)(offset + base) == value) break;
            offset = index << 4;
        } while ((s32)index < count);
    }
    return base + offset;
}

