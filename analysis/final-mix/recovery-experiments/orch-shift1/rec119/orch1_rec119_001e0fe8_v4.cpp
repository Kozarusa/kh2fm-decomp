#include "../common/types.h"
extern "C" s32 D_00352bd0;
extern "C" u8* func_001e2760(s32, s32);

void func_001e0fe8(s32* object) {
    u8* pointer = func_001e2760(D_00352bd0, object[8]);
    u8 old = *pointer;
    s8 value = old + 10;
    if ((s8)old < 0) {
        object[9] = 2;
    } else {
        *(volatile u8*)pointer = value;
        if (value < 0) {
            value = -128;
        }
        *pointer = value;
        pointer[3] = 10;
        pointer[1] = 0;
        pointer[2] = 0;
    }
}
