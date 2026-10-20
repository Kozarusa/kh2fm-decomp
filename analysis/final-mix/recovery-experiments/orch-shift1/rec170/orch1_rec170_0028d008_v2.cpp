#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u8* D_0035f3fc;
extern "C" s32 D_0035f410;
u32 func_0028d008(u32 index) {
    u32 result;
    if (D_0035f3fc != 0) {
        result = func_00139d78(D_0035f3fc + index * 408);
    } else {
        result = 0;
    }
    s32 shifted;
    if (result != 0) {
        asm("srav %0,%1,%2" : "=r"(shifted) : "r"(D_0035f410), "r"(index)); // why: native shift wraps the count; C15 primitive from 00194830
        if ((shifted & 1) != 0) {
        result = 0;
    }
    return result;
}

