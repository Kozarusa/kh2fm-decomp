#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" s32 func_0016c028(...);

void func_00171418(s32** object) {
    Quad* source = (Quad*)func_0016c028((*object)[1]);
    Quad* dest = (Quad*)0x01c5f480;
    if (source != dest) {
        *dest = *source;
    }
    *object = (s32*)dest;
}
