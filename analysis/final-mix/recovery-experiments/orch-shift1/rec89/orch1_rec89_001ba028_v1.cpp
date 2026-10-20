#include "../common/types.h"
extern "C" s32 D_01d48da0;

u8 func_001ba028(s32 target) {
    s32 current = 0;
    while (1) {
        s32 next = D_01d48da0;
        if (current != 0) {
            next = *(s32*)(current + 0x8b4);
        }
        if (next == 0) {
            return 0;
        }
        current = next;
        if (next == target) {
            return 1;
        }
    }
}
