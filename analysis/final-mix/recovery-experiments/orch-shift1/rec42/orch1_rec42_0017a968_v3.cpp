#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" s8 D_01c60500;
extern "C" kn::FVector D_01c60510;
extern "C" u8 D_0017bef8[];
extern "C" void func_002fd188(u8*);

kn::FVector func_0017a968() {
    if (D_01c60500 == 0) {
        f32 zero = 0.0f;
        f32* v = (f32*)&D_01c60510;
        v[3] = zero;
        D_01c60500 = 1;
        v[0] = zero;
        v[1] = zero;
        v[2] = zero;
        func_002fd188(D_0017bef8);
    }
    return D_01c60510;
}