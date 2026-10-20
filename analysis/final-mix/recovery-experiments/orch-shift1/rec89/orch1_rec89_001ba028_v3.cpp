#include "../common/types.h"
extern "C" s32 D_01d48da0;

u8 func_001ba028(s32 target) {
    s32 current = 0;
    u8 result = 0;
    while (1) {
        s32 next = current ? *(s32*)(current + 0x8b4) : D_01d48da0;
        if (next == 0) {
            break;
        }
        current = next;
        if (next == target) {
            result = 1;
            break;
        }
    }
    return result;
}
