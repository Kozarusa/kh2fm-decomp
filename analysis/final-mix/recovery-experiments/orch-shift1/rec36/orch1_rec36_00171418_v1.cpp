#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" s32 func_0016c028(...);
extern "C" Quad D_01c5f480;

void func_00171418(s32** object) {
    Quad* source = (Quad*)func_0016c028((*object)[1]);
    if (source != &D_01c5f480) {
        D_01c5f480 = *source;
    }
    *object = (s32*)&D_01c5f480;
}
