#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" void func_001391a8(u8*, kn::FVector*);
extern "C" s32 func_00139d78(u8*);

void func_0013e3b0(u8* object, kn::FVector* source) {
    kn::FVector copy;
    // why: aligned 128-bit copy through t0 without the self-assignment guard, as in accepted fm_copy_helpers.cpp
    asm volatile("lq $8,0(%1); sq $8,0(%0)" : : "r"(&copy), "r"(source) : "$8", "memory");
    u8* inner = object + 0x1c0;
    func_001391a8(object, &copy);
    if (func_00139d78(inner)) {
        // why: second aligned 128-bit copy through t0, same primitive
        asm volatile("lq $8,0(%1); sq $8,0(%0)" : : "r"(&copy), "r"(source) : "$8", "memory");
        func_001391a8(inner, &copy);
    }
}
