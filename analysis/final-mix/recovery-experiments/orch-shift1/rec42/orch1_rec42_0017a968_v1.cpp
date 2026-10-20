#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" s8 D_01c60500;
extern "C" kn::FVector D_01c60510;
extern "C" u8 D_0017bef8[];
extern "C" void func_002fd188(u8*);

kn::FVector* func_0017a968(kn::FVector* out) {
    if (D_01c60500 == 0) {
        f32* v = (f32*)&D_01c60510;
        v[3] = 0.0f;
        D_01c60500 = 1;
        v[0] = 0.0f;
        v[1] = 0.0f;
        v[2] = 0.0f;
        func_002fd188(D_0017bef8);
    }
    *out = D_01c60510;
    return out;
}