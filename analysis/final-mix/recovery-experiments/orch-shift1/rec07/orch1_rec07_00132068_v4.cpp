#include "../common/types.h"

s8* func_00132068(s8* base, s32 index) {
    s8* result = base;
    if (base != 0) {
        s16 tag = *(s16*)base;
        if (tag != -1) {
            if (tag != 0) {
                result = 0;
            }
        } else {
            result = base + *(s32*)(base + index * 4 + 8);
        }
    } else {
        result = 0;
    }
    return result;
}
