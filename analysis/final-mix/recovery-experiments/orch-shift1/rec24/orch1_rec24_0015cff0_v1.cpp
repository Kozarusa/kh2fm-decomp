#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" Quad D_004f37b0;
extern "C" Quad D_004f37a0;
extern "C" Quad D_004f3790;
extern "C" Quad D_004f3780;
extern "C" Quad D_004f37e0;
extern "C" Quad D_004f37d0;

void func_0015cff0() {
    Quad* dst = &D_004f37b0;
    Quad* src = &D_004f37a0;
    if (dst != src) {
        *dst = *src;
    }
    dst = &D_004f3790;
    src = &D_004f3780;
    if (dst != src) {
        *dst = *src;
    }
    dst = &D_004f37e0;
    src = &D_004f37d0;
    if (dst != src) {
        *dst = *src;
    }
}
