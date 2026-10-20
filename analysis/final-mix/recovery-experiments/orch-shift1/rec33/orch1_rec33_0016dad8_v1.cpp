#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" kn::FVector D_004f62a0;
extern "C" kn::FVector func_0017d050(u32);

void func_0016dad8(u32* object) {
    D_004f62a0 = func_0017d050(object[0]);
    object[0] = (u32)&D_004f62a0;
}
