#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" s8 D_01c60500;
extern "C" f32 D_01c60510[4];
extern "C" u8 D_0017bef8[];
extern "C" void func_002fd188(u8*);

Quad* func_0017a968(Quad* out) {
    if (D_01c60500 == 0) {
        f32 zero = 0.0f;
        D_01c60510[3] = zero;
        D_01c60500 = 1;
        D_01c60510[0] = zero;
        D_01c60510[1] = zero;
        D_01c60510[2] = zero;
        func_002fd188(D_0017bef8);
    }
    *out = *(Quad*)D_01c60510;
    return out;
}