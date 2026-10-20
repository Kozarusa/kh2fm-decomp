#include "../common/types.h"
extern "C" u32 D_00347fb0;
extern "C" u32 D_00347fd8;

void func_0013a820(s32 mode, s32 code) {
    if (code == 0xffff) {
        if (mode == 1) {
            s32 count = 3;
            u32* cursor = &D_00347fb0;
            D_00347fb0 = 0;
            cursor[1] = 0;
            do {
                cursor[2] = 0;
                count--;
                cursor[3] = 0;
                cursor += 2;
            } while (count >= 0);
        }
    }
    if (code == 0xffff) {
        if (mode == 1) {
            D_00347fd8 = 0;
            u32* pointer = &D_00347fd8;
            pointer[1] = 0;
            pointer[3] = 0;
            pointer[2] = 0;
        }
    }
}
