#include "../common/types.h"

s8* func_00132068(s8* base, s32 index) {
    if (base != 0) {
        s16 tag = *(s16*)base;
        if (tag == -1) {
            return base + *(s32*)(base + index * 4 + 8);
        }
        if (tag == 0) {
            return base;
        }
    }
    return 0;
}
