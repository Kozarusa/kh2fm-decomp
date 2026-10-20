#include "../common/types.h"
extern "C" u32 func_001de4b0(s32,u64,s32);
s32 func_0022e0a8(u8* object) {
    s32 result = 0;
    s32 output;
    while (1) {
        result = func_001de4b0((s32)(object + 16), 0, result);
        output = 1;
        if (result == 0) {
            output = 0;
            break;
        } else {
            if (*(s32*)(object + 12) == result) break;
        }
    }
    return output;
}
