#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" kn::FVector func_0017d348(kn::FVector*, u32, f32);

void func_0016d800(u32* object) {
    kn::FVector* vector = (kn::FVector*)object[0];
    u32 count = ((volatile u32*)object)[1];
    f32 amount = *(f32*)&object[2];
    *vector = func_0017d348(vector, count, amount);
}
