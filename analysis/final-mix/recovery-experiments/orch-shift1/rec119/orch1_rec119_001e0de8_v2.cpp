#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" Quad* func_001e0cc8(Quad*);
extern "C" Quad* func_001e0ce8(Quad*);

void func_001e0de8(Quad* dest) {
    Quad* source = func_001e0cc8(dest);
    Quad* cursor = dest;
    if (cursor == source) {
        ((u32*)cursor)[3] = 0;
    } else {
        *cursor = *source;
        ((u32*)cursor)[3] = 0;
    }
    source = func_001e0ce8(dest);
    cursor = cursor + 1;
    if (cursor != source) {
        *cursor = *source;
    }
}
