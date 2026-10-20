#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

void func_001a49a0(u8* object, Quad* first, Quad* second) {
    Quad* destination_a = (Quad*)(object + 0xe0);
    Quad* destination_b = (Quad*)(object + 0xf0);
    if (destination_a != first) {
        *destination_a = *first;
    }
    if (destination_b != second) {
        *destination_b = *second;
    }
    *(u32*)(object + 4) = *(u32*)(object + 4) | 0x20;
}