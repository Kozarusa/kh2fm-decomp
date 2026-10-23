#include "../common/types.h"
extern "C" u32 D_003616f8[];
extern "C" u32 func_002b6adc(u32,u32);
extern "C" s32 func_002b6ab8();

s32 func_002bd1c0() {
    u32* base = D_003616f8;
    u32* pointer = base + 11;
    s32 count = 13;
    do {
        count--;
        func_002b6adc(2, *pointer);
        func_002b6adc(0, *pointer);
        pointer++;
    } while (count >= 0);
    return func_002b6ab8();
}
