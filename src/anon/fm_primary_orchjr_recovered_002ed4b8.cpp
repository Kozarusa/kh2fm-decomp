#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" u32 D_00363748;
extern "C" u32 func_002ed350(u32, u32, u32, kn::FVector*, kn::FVector*);

u32 func_002ed4b8(u32 first, u32 second, kn::FVector* third, kn::FVector* fourth) {
    kn::FVector copy_fourth;
    asm volatile("lq $8, 0(%1);" "sq $8, 0(%0);" : : "r"(&copy_fourth), "r"(fourth) : "t0", "memory"); // why: FVector copy without self-check (0015d058 precedent), operator= kept the check (v2)
    kn::FVector copy_third;
    asm volatile("lq $8, 0(%1);" "sq $8, 0(%0);" : : "r"(&copy_third), "r"(third) : "t0", "memory"); // why: FVector copy without self-check (0015d058 precedent), operator= kept the check (v2)
    u32 result = func_002ed350(D_00363748, first, second, &copy_third, &copy_fourth);
    return result ? result + 48 : 0;
}
