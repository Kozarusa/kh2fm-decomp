#include "../common/types.h"
extern "C" s32 D_01d49328[];
extern "C" s32 D_01d49348;
extern "C" s32 D_01d4934c;
extern "C" s32 D_01d49350[];

void func_001bff88() {
    s32 index = 7;
    s32* pointer = D_01d49328;
    do {
        *pointer = 0;
        index--;
        pointer++;
    } while (index >= 0);
    D_01d4934c = 0x100;
    D_01d49348 = 0;
    s32* tail = D_01d49350;
    *tail = 0;
    tail[1] = 0;
}
