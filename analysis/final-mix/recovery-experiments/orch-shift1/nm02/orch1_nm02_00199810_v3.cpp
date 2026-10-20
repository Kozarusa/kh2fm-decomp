#include "../common/types.h"
extern "C" u8 D_00350378;
extern "C" u8 D_0032bae2;
extern "C" u8* func_0016e920(u32);
extern "C" s32 func_0016f448(u32);

s32 func_00199810(u8* object) {
    // why: the original keeps the result in t4 ($12)
    register s32 result asm("$12");
    u8* data = func_0016e920(*(u32*)object);
    if (data == 0) {
        result = 0;
    } else if (D_00350378 != 0 && func_0016f448(data[4]) >= 2000) {
        result = 0;
    } else {
        result = 1;
        if (object[28] == 1) {
            u8 current = *(volatile u8*)(object + 29);
            u8 mark = D_0032bae2;
            if (current == mark) {
                result = 1;
            } else {
                result = 0;
            }
        }
    }
    return result;
}
