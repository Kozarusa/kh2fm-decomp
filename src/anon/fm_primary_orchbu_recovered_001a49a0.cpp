#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

void func_001a49a0(u8* object, Quad* first, Quad* second) {
    Quad* destination = (Quad*)(object + 0xe0);
    // why: keeps the pointer in a register so the quad store uses offset 0
    asm("" : "+r"(destination));
    if (destination != first) {
        // why: original holds the quad in t0 (register 8)
        register Quad value asm("$8") = *first;
        *destination = value;
    }
    destination = (Quad*)(object + 0xf0);
    // why: keeps the pointer in a register so the quad store uses offset 0
    asm("" : "+r"(destination));
    if (destination != second) {
        // why: original holds the quad in t0 (register 8)
        register Quad value asm("$8") = *second;
        *destination = value;
    }
    *(u32*)(object + 4) = *(u32*)(object + 4) | 0x20;
}
