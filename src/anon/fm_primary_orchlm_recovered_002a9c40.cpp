#include "../common/types.h"
extern "C" u32 func_00294000(u32);
// why: no recovered call site; a0 is a 16-byte entry pointer and v0 is read as an integer state
extern "C" s32 func_002a99c8(void*);

s32 func_002a9c40(u32 id) {
    s32 index = 0;
    s32 result = 0;
    u32 object = func_00294000(8);
    s32 count = *(s32*)(object + 8);
    u8* entries = (u8*)(object + 16);
    if (count > 0) {
        u8* cursor = entries;
        do {
            if (id == *(u16*)(cursor + 2)) {
                if ((u32)(func_002a99c8(cursor) - 1) < 2) {
                    result = 1;
                    break;
                }
                count = *(s32*)(object + 8);
            }
            index++;
            cursor += 16;
        } while (index < count);
    }
    return result;
}
