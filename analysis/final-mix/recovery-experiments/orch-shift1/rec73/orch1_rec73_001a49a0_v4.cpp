#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

void func_001a49a0(u8* object, Quad* first, Quad* second) {
    // why: original keeps the destination pointer in t7 (register 15)
    register Quad* destination asm("$15") = (Quad*)(object + 0xe0);
    // why: keeps the pointer in a register so the quad store uses offset 0
    asm("" : "+r"(destination));
    if (destination != first) {
        *destination = *first;
    }
    destination = (Quad*)(object + 0xf0);
    // why: keeps the pointer in a register so the quad store uses offset 0
    asm("" : "+r"(destination));
    if (destination != second) {
        *destination = *second;
    }
    *(u32*)(object + 4) = *(u32*)(object + 4) | 0x20;
}