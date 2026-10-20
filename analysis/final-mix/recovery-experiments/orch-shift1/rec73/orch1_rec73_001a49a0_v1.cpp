#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

void func_001a49a0(u8* object, Quad* first, Quad* second) {
    Quad* destination = (Quad*)(object + 0xe0);
    if (destination != first) {
        *destination = *first;
    }
    destination = (Quad*)(object + 0xf0);
    if (destination != second) {
        *destination = *second;
    }
    *(u32*)(object + 4) = *(u32*)(object + 4) | 0x20;
}