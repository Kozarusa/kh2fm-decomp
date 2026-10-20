#include "../common/types.h"
extern "C" s32 D_00350f18;
extern "C" s32 D_01d44400;
extern "C" u8 D_01d44440[];

u8* func_001b1ff0(s32 index) {
    u8* result = 0;
    if (index != -1) {
        s32 count = D_01d44400;
        D_00350f18 = 2;
        D_01d44400 = count + 1;
        result = D_01d44440;
    }
    return result;
}
