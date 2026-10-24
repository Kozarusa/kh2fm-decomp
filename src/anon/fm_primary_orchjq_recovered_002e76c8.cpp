#include "../common/types.h"

// Preserve original registry aliases.
void func_002e76c8(u8* object) asm("_Z13func_002e76c8Pv");

void func_002e76c8(u8* object) {
    u8* cursor;
    s32 count;
    s32 tail;
    object[1] = 0;
    object[0x8c] = 1;
    asm volatile("" ::: "memory"); // why: keeps store order
    cursor = object;
    asm volatile("" ::: "memory"); // why: keeps store order
    object[0] = 1;
    count = 15;
    object[2] = 0;
    object[0x8a] = 0;
    asm volatile("" ::: "memory"); // why: keeps store order
    object[0x8b] = 1;
    do {
        cursor[0x9a] = 0;
        count = count - 1;
        cursor[0xaa] = 0;
        cursor = cursor + 1;
    } while (count >= 0);
    object = object + 0xba;
    tail = 127;
    do {
        *object = 0;
        tail = tail - 1;
        object = object + 1;
    } while (tail >= 0);
}
