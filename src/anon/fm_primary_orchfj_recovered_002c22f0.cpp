#include "../common/types.h"
extern "C" bool func_00181500(u32);

s32 func_002c22f0(s32 object) {
    u16* pointer = (u16*)(object + 4);
    s32 index = 2;
    s32 count = 0;
    do {
        u16 value = *pointer;
        pointer += 2;
        if (value != 0) {
            if (func_00181500(value)) {
                count = count + 1;
            }
        }
        index = index - 1;
    } while (index >= 0);
    return count;
}
