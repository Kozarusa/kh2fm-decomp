#include "../common/types.h"
extern "C" u8* D_004f3b38;
extern "C" void func_001604d8(u8*);

void func_00160f10(s32 value) {
    u8* node = 0;
    u8* next;
    while ((node = next = node ? *(u8**)(node + 0x80) : D_004f3b38) != 0) {
        // why: keeps the body reading the loaded pointer (a0), not the copy in s0
        asm("" : "+r"(next));
        if (*(s32*)(next + 0x1a8) == value) {
            func_001604d8(next);
        }
    }
}