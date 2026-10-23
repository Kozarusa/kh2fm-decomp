#include "../common/types.h"
extern "C" u32 func_001ca448(void);

u32 func_001cf560(u8* object) {
    u32 result = 0;
    if (func_001ca448() != 0 || *(s32*)(object + 0x154) == 44) {
        result = 1;
    }
    return result;
}
