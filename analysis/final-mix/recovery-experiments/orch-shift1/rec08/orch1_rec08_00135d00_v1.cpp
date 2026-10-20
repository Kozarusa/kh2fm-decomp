#include "../common/types.h"

s32 func_00135d00(u8* object, s32 index) {
    s32 count = *(s32*)(object + 12);
    s32 result = 0;
    if (count != 0) {
        while (index < 0) {
            index = index + count;
        }
        if (index >= count) {
            index = index - count;
            while (index >= count) {
                index = index - count;
            }
        }
        result = *(s32*)(object + index * 4 + 16);
    }
    return result;
}