#include "../common/types.h"
extern "C" u8* D_004f3b38;
extern "C" void func_001604d8(u8*);

static inline u8* nextNode(u8* node) {
    if (node != 0) {
        return *(u8**)(node + 0x80);
    }
    return D_004f3b38;
}

void func_00160f10(s32 value) {
    u8* node = 0;
    u8* next;
    while ((next = nextNode(node)) != 0) {
        node = next;
        if (*(s32*)(next + 0x1a8) == value) {
            func_001604d8(next);
        }
    }
}