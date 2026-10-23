#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u32 func_00142940(u32 target, void* block);

u32 func_00165830(u8* object, u8* source) {
    Quad copy[4];
    volatile Quad* src = (volatile Quad*)source;
    volatile Quad* dst = (volatile Quad*)copy;
    // why: original block copy loads then stores in t0-t3 ($8-$11)
    register Quad a asm("$8") = src[0];
    register Quad b asm("$9") = src[1];
    register Quad c asm("$10") = src[2];
    register Quad d asm("$11") = src[3];
    dst[0] = a;
    dst[1] = b;
    dst[2] = c;
    dst[3] = d;
    // why: keeps the field read after the block copy stores
    asm volatile("" ::: "memory");
    u32 target = *(u32*)(object + 4);
    return func_00142940(target, copy);
}
