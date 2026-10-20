#include "../common/types.h"
extern "C" s16* D_0035f230;

s32 func_0027ae78(s32 value) {
    s32 count = 0;
    s32 index = 0;
    s16* object = D_0035f230;
    do {
        if (index != 6) {
            u8 flag = (((*object >> index) ^ 1) & 1);
            if (!flag) {
            if (value == count) break;
            count++;
            }
        }
        index++;
    } while (index < 8);
    return index;
}
