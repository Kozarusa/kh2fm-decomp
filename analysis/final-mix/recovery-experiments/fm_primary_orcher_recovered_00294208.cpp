#include "../common/types.h"
extern "C" u32 func_00294000(u64);
extern "C" u64 func_002941d8(...);

u64 func_00294208(s32 value) {
    u32 object = func_00294000(0);
    s32 count = *(s32*)(object + 8);
    s8* cursor = (s8*)(object + 16);
    s32 index = 0;
    if (count > 0) {
        do {
            if (*cursor == value) {
                u64 result = func_002941d8(cursor);
                asm("" : "+r"(result)); // why: original returns the callee result through its own epilogue
                return result;
            }
            ++index;
            cursor += 16;
        } while (index < count);
    }
    return 0;
}
