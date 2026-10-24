#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" kn::FVector D_01e2bf90;

void func_002e8ca8(kn::FVector** object) {
    kn::FVector copy;
    // why: aligned 128-bit copy through t0 without the self-assignment guard, as in accepted 0013e3b0 and fm_copy_helpers.cpp
    asm volatile("lq $8,0(%1); sq $8,0(%0)" : : "r"(&copy), "r"(*object) : "$8", "memory");
    D_01e2bf90 = copy;
    *object = &D_01e2bf90;
}
