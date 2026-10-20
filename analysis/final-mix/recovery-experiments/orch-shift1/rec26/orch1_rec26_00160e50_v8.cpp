#include "../common/types.h"
extern "C" u8* D_004f3b38;
extern "C" void func_00160d38(u8*);

void func_00160e50(s32 value) {
    u8* node = 0;
    u8* next;
    for (;;) {
        if (node != 0) {
            next = *(u8**)(node + 0x80);
        } else {
            next = D_004f3b38;
        }
        if ((node = next) == 0) {
            return;
        }
        if (*(s32*)(next + 0x1a8) == value) {
            func_00160d38(next);
        }
    }
}