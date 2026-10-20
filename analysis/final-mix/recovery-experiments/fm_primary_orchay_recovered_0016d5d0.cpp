#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" s8 D_004f6330;
extern "C" kn::FVector D_004f6340;
extern "C" u8 D_0016e898[];
extern "C" void func_002fd188(u8*);
extern "C" kn::FVector func_0017d538(u32, f32);

void func_0016d5d0(u32* object) {
    if (D_004f6330 == 0) {
        D_004f6330 = 1;
        func_002fd188(D_0016e898);
    }
    D_004f6340 = func_0017d538(object[0], *(f32*)&object[1]);
    object[0] = (u32)&D_004f6340;
}
