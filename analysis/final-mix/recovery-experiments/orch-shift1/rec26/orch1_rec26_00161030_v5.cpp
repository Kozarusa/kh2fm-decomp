#include "../common/types.h"
extern "C" u8* D_004f3b38;

u8* func_00161030(s32 index) {
    u8* node = 0;
    s32 count = 0;
    u8* next;
    while ((next = node ? *(u8* volatile*)(node + 0x80) : D_004f3b38), node = next, next != 0) {
        if (*(s32*)(next + 0x1b0) == 0) {
            if (count == index) {
                return next;
            }
            count++;
        }
    }
    return 0;
}