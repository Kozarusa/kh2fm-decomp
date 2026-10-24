#include "../common/types.h"
extern "C" s32 func_001b9bc8(s32);

s32 func_002be908(s32 object) {
    while ((object = func_001b9bc8(object)) != 0) {
        if ((*(u32*)(object + 0x588) & 0x40000000) != 0) {
            return object;
        }
    }
    return 0;
}
