#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" Quad* func_001e0cc8(Quad*);
extern "C" Quad* func_001e0ce8(Quad*);

void func_001e0de8(Quad* dest) {
    Quad* source = func_001e0cc8(dest);
    if (dest != source) {
        *dest = *source;
    }
    ((u32*)dest)[3] = 0;
    source = func_001e0ce8(dest);
    if (dest + 1 != source) {
        dest[1] = *source;
    }
}
