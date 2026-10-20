#include "../common/types.h"
extern "C" u32 func_001d5370(void*, s32, s32);
extern "C" u32 func_002534e0(...);

u32 func_001bba30(u8* object) {
    u32 buffer[2];
    buffer[0] = 0;
    buffer[1] = 0;
    u32 result = 0;
    s32 target = *(s32*)(object + 0x48);
    if (target != 0) {
        u8 count = *(u8*)(*(u32*)(object + 8) + 12);
        if (count == 0) {
            result = 0;
        } else {
            func_001d5370(buffer, target, count - 1);
            func_002534e0(buffer[1], buffer[0]);
            result = 1;
        }
    }
    return result;
}