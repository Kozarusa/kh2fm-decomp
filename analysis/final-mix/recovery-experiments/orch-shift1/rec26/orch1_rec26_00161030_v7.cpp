#include "../common/types.h"
extern "C" s32 D_004f3b38;

s32 func_00161030(s32 index) {
    s32 node = 0;
    s32 count = 0;
    s32 next;
    while ((next = node ? *(s32*)(node + 0x80) : D_004f3b38), node = next, next != 0) {
        if (*(s32*)(next + 0x1b0) == 0) {
            if (count == index) {
                return next;
            }
            count++;
        }
    }
    return 0;
}