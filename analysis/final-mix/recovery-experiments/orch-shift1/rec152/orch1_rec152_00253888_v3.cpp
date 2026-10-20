#include "../common/types.h"
extern "C" u8 D_01dae6c0[];
extern "C" s32 D_0035eee0[];
extern "C" s32 D_0035ef50;
extern "C" s32 D_0035ef54;
void func_00253888(s32 value) {
    s32 base = (s32)D_01dae6c0;
    s32* pointer = D_0035eee0;
    s32 result = 0;
    s32 count = 6;
    do {
        s32 object = pointer[3];
        --count;
        if (object != 0) {
            s32 current = pointer[0];
            if (current < value) { } else {
                s32 offset = object - base;
                pointer[0] = 0;
                pointer[1] = 0;
                if (current == value) result = offset;
                pointer[3] = 0;
                pointer[2] = 0;
            }
        }
        pointer += 4;
    } while (count >= 0);
    D_0035ef50 = result;
    D_0035ef54 = value;
}


