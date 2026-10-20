#include "../common/types.h"
extern "C" u32 func_001de4b0(s32,u64,s32);
s32 func_0022e0a8(u8* object) {
    s32 result = 0;
    do {
        result = func_001de4b0((s32)(object + 16), 0, result);
        if (result == 0) return 0;
    } while (*(s32*)(object + 12) != result);
    return 1;
}
