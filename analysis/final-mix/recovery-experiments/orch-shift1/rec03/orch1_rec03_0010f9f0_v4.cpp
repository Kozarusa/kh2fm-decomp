#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

void func_0010f9f0(u8* object, Quad* source, u8 flag) {
    // why: original keeps the destination address in t7 and uses a zero-offset store
    register Quad* destination asm("$15") = (Quad*)(object + 0xc00);
    asm("" : "+r"(destination));
    if (destination != source) {
        // why: original moves the quad through t0
        register Quad value asm("$8") = *source;
        *destination = value;
    }
    if (flag != 0) {
        *(u32*)(object + 0xb7c) |= 0x80;
    } else {
        *(u32*)(object + 0xb7c) &= 0xffffff7f;
    }
}
