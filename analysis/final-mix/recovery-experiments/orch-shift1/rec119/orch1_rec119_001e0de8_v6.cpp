#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" Quad* func_001e0cc8(Quad*);
extern "C" Quad* func_001e0ce8(Quad*);

void func_001e0de8(Quad* dest) {
    Quad* source = func_001e0cc8(dest);
    if (dest != source) {
        register Quad first asm("$8") = *source; // why: original uses t0 for the quad copy
        *dest = first;
    }
    ((u32*)dest)[3] = 0;
    asm volatile("" ::: "memory"); // why: keeps the argument move after the zero store
    source = func_001e0ce8(dest);
    dest = dest + 1;
    if (dest != source) {
        register Quad second asm("$8") = *source; // why: original uses t0 for the quad copy
        *dest = second;
    }
}

