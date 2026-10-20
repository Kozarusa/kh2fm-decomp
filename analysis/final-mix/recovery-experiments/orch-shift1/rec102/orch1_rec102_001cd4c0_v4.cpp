#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u32 func_001bbf00(void);
extern "C" u8 D_0032bae0[];
extern "C" u8 D_00350378;

u32 func_001cd4c0(void) {
    // why: original keeps the result in t7 ($15) on every path
    register u32 result asm("$15");
    if (func_001bbf00() != 0) {
        result = 1;
    } else if (*(u16*)(D_0032bae0 + 4) < 51) {
        if (D_00350378 != 0) {
            result = 0;
        } else {
            result = 0;
            if (func_001bb4a0() == 0) {
                result = 1;
            }
        }
    } else {
        result = 0;
    }
    return result;
}