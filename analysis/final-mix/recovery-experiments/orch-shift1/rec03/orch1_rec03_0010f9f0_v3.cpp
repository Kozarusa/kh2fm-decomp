#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

void func_0010f9f0(u8* object, Quad* source, u8 flag) {
    Quad* destination = (Quad*)(object + 0xc00);
    // why: keeps the destination address in a register so the store uses a zero offset
    asm("" : "+r"(destination));
    if (destination != source) {
        *destination = *source;
    }
    if (flag != 0) {
        *(u32*)(object + 0xb7c) |= 0x80;
    } else {
        *(u32*)(object + 0xb7c) &= 0xffffff7f;
    }
}
