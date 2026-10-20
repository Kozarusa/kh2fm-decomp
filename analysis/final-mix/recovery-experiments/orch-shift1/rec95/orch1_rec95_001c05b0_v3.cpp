#include "../common/types.h"
extern "C" u32 D_01d49328[];
extern "C" s32 D_01d49350;
extern "C" s32 D_01d49354;

void func_001c05b0(s32 mode, s32 id) {
    if (id == 0xffff) {
        if (mode == 1) {
            s32 index = 7;
            u32* pointer = D_01d49328;
            do {
                *pointer = 0;
                index--;
                pointer++;
            } while (index >= 0);
        }
    }
    if (id == 0xffff) {
        if (mode == 1) {
            D_01d49350 = 0;
            D_01d49354 = 0;
        }
    }
}

