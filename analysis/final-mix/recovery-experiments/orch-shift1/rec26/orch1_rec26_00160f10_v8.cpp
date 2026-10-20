#include "../common/types.h"
extern "C" u8* D_004f3b38;
extern "C" void func_001604d8(u8*);

void func_00160f10(s32 value) {
    u8* node = 0;
    // why: original reads the loaded pointer in a0 while s0 holds the copy
    register u8* next asm("$4");
    while ((node = next = node ? *(u8**)(node + 0x80) : *(volatile u8**)&D_004f3b38) != 0) {
        if (*(s32*)(next + 0x1a8) == value) {
            func_001604d8(next);
        }
    }
}