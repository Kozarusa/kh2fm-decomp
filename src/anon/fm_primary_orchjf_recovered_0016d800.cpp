#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" u32 func_0017d348(kn::FVector*, kn::FVector*, u32, f32);

u32 func_0016d800(u32* object) {
    kn::FVector* vector = (kn::FVector*)object[0];
    u32 count = object[1];
    kn::FVector result;
    u32 value = func_0017d348(&result, vector, count, *(f32*)&object[2]);
    *vector = result;
    return value;
}
