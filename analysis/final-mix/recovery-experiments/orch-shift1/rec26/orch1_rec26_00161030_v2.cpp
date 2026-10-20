#include "../common/types.h"
extern "C" u8* D_004f3b38;

u8* func_00161030(s32 index) {
    u8* node = 0;
    s32 count = 0;
    // why: original keeps the loaded pointer in v0 and a copy in t6
    register u8* next asm("$2");
    while ((node = next = node ? *(u8**)(node + 0x80) : D_004f3b38) != 0) {
        if (*(s32*)(next + 0x1b0) == 0) {
            if (count == index) {
                return next;
            }
            count++;
        }
    }
    return 0;
}