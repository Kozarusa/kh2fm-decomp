#include "../common/types.h"
extern "C" u8* D_004f3b38;
extern "C" void func_00160d38(u8*);

void func_00160e50(s32 value) {
    u8* node = 0;
    u8* next;
    while ((node = next = node ? *(u8**)(node + 0x80) : D_004f3b38) != 0) {
        if (*(s32*)(node + 0x1a8) == value) {
            func_00160d38(node);
        }
    }
}