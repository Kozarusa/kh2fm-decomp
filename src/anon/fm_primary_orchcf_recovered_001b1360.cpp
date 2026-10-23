#include "../common/types.h"
extern "C" s32 func_001b9bc8(s32);

void func_001b1360(s32 match, s32 replacement) {
    s32 entry = 0;
    while ((entry = func_001b9bc8(entry)) != 0) {
        u8* pointer = (u8*)entry;
        if (*(s32*)(pointer + 0x4a4) == 2) {
            if (*(s32*)(pointer + 0x4d0) == match) {
                *(s32*)(pointer + 0x4d0) = replacement;
            }
        }
    }
}
