#include "../common/types.h"
extern "C" u32 func_001d5370(...);
extern "C" u32 func_002534e0(...);

u32 func_001bba30(u8* object) {
    u32 buffer[2];
    buffer[0] = 0;
    buffer[1] = 0;
    u32 result = 0;
    s32 target = *(s32*)(object + 0x48);
    if (target != 0) {
        u8 count = *(u8*)(*(u32*)(object + 8) + 12);
        while (count != 0) {
            func_001d5370(buffer, target, count - 1);
            func_002534e0(buffer[1], buffer[0]);
            return 1;
        }
        result = 0;
    }
    return result;
}
