#include "../common/types.h"
extern "C" u32 D_0035f5e4;
// why: types copied from the recovered definition fm_primary_orchex_recovered_002a4990.cpp; extern "C" because
// the C++ form fails the isolated link (probe linker script defines only the plain symbol, see v1)
extern "C" s32 func_002a4990(s32 value);

s32 func_002a4ad8(s32 value) {
    if (value < 0) {
        value = *(s32*)(D_0035f5e4 + 0x1088);
    }
    s32 count = func_002a4990(*(s32*)(D_0035f5e4 + 0x1084) + value / 8);
    s32 total = 0;
    if (count > 0) {
        u8* pointer = (u8*)(D_0035f5e4 + 0x1001);
        do {
            count--;
            total += *pointer;
            pointer += 8;
        } while (count != 0);
    }
    return value - (total - *(s32*)(D_0035f5e4 + 0x1084)) * 8;
}
