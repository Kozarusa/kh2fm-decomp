#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" s8 D_01c60cf0;
extern "C" kn::FVector D_01c60d00;
extern "C" u8 D_001900c8[];
extern "C" void func_002fd188(u8*);
extern "C" kn::FVector func_001a4b78(u32);

void func_0018f940(u32* object) {
    if (D_01c60cf0 == 0) {
        D_01c60cf0 = 1;
        func_002fd188(D_001900c8);
    }
    D_01c60d00 = func_001a4b78(object[0]);
    object[0] = (u32)&D_01c60d00;
}
