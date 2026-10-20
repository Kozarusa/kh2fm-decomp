#include "../common/types.h"
extern "C" u8 D_00350378;
extern "C" volatile u8 D_0032bae2; // why: keeps the compare as a branch
extern "C" u8* func_0016e920(u32);
extern "C" s32 func_0016f448(u32);

s32 func_00199810(u8* object) {
    s32 result;
    u8* data = func_0016e920(*(u32*)object);
    if (data == 0) {
        result = 0;
    } else {
        if (D_00350378 != 0) {
            if (func_0016f448(data[4]) >= 2000) {
                return 0;
            }
        }
        result = 1;
        if (object[28] == 1) {
            result = 0;
            if (object[29] == D_0032bae2) {
                result = 1;
            }
        }
    }
    return result;
}

