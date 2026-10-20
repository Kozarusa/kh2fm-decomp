#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" s32 func_0016c028(...);
extern "C" Quad D_01c5f480[];

void func_00171418(s32** object) {
    Quad* source = (Quad*)func_0016c028((*object)[1]);
    Quad* dest = D_01c5f480;
    // why: keeps the address in one register instead of folding the low half into sq
    asm("" : "+r"(dest));
    if (source != dest) {
        *dest = *source;
    }
    *object = (s32*)dest;
}
