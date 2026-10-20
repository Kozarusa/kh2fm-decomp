#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u32 func_001bbf00(void);
extern "C" u16 D_0032bae0[];
extern "C" u8 D_00350378;

u32 func_001cd4c0(void) {
    if (func_001bbf00() != 0) {
        return 1;
    }
    if (D_0032bae0[2] < 51) {
        if (D_00350378 != 0) {
            return 0;
        }
        if (func_001bb4a0() == 0) {
            return 1;
        }
    }
    return 0;
}