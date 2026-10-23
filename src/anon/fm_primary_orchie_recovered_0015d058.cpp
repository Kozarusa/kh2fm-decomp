#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" kn::FVector D_004f3760;
extern "C" kn::FVector D_004f3770;
extern "C" kn::FVector D_004f3780;
extern "C" kn::FVector D_004f3790;
extern "C" kn::FVector D_004f37a0;
extern "C" kn::FVector D_004f37b0;
extern "C" f32 D_0036b400;
extern "C" f32 D_0036b404;
extern "C" f32 D_0036b408;
extern "C" f32 D_0036b40c;
extern "C" f32 D_0036b410;
extern "C" kn::FVector* func_0013f6e8(kn::FVector* out, kn::FVector* first, kn::FVector* second, kn::FVector* third, f32 weight, f32 x, f32 y, f32 z);

kn::FVector* func_0015d058(kn::FVector* position, kn::FVector* target) {
    D_004f37a0 = *target;
    D_004f3780 = *position;
    kn::FVector result;
    kn::FVector first;
    kn::FVector second;
    kn::FVector third;
    asm volatile("lq $8, 0(%1);" "sq $8, 0(%0);" : : "r"(&first), "r"(&D_004f3760) : "t0", "memory"); // why: FVector copy without self-check, plain copy failed (v2)
    asm volatile("lq $8, 0(%1);" "sq $8, 0(%0);" : : "r"(&second), "r"(&D_004f37a0) : "t0", "memory"); // why: FVector copy without self-check, plain copy failed (v2)
    asm volatile("lq $8, 0(%1);" "sq $8, 0(%0);" : : "r"(&third), "r"(&D_004f37b0) : "t0", "memory"); // why: FVector copy without self-check, plain copy failed (v2)
    register f32* xAddress asm("$15") = &D_0036b400; // why: original forms each float address in t7
    asm("" : "+r"(xAddress)); // why: original forms the full address in t7 before lwc1 0(t7)
    register f32 x asm("$f20") = *xAddress; // why: original keeps this value in $f20
    register f32* yAddress asm("$15") = &D_0036b404; // why: original forms each float address in t7
    asm("" : "+r"(yAddress)); // why: original forms the full address in t7 before lwc1 0(t7)
    register f32 y asm("$f21") = *yAddress; // why: original keeps this value in $f21
    register f32* weightAddress asm("$15") = &D_0036b408; // why: original forms each float address in t7
    asm("" : "+r"(weightAddress)); // why: original forms the full address in t7 before lwc1 0(t7)
    f32 weight = *weightAddress;
    register f32* zAddress asm("$15") = &D_0036b40c; // why: original forms each float address in t7
    asm("" : "+r"(zAddress)); // why: original forms the full address in t7 before lwc1 0(t7)
    register f32 z asm("$f22") = *zAddress; // why: original keeps this value in $f22
    func_0013f6e8(&result, &first, &second, &third, weight, x, y, z);
    D_004f3760 = result;
    *target = D_004f3760;
    asm volatile("lq $8, 0(%1);" "sq $8, 0(%0);" : : "r"(&first), "r"(&D_004f3770) : "t0", "memory"); // why: FVector copy without self-check, plain copy failed (v2)
    asm volatile("lq $8, 0(%1);" "sq $8, 0(%0);" : : "r"(&second), "r"(&D_004f3780) : "t0", "memory"); // why: FVector copy without self-check, plain copy failed (v2)
    asm volatile("lq $8, 0(%1);" "sq $8, 0(%0);" : : "r"(&third), "r"(&D_004f3790) : "t0", "memory"); // why: FVector copy without self-check, plain copy failed (v2)
    register f32* lastWeightAddress asm("$15") = &D_0036b410; // why: original forms each float address in t7
    asm("" : "+r"(lastWeightAddress)); // why: original forms the full address in t7 before lwc1 0(t7)
    f32 lastWeight = *lastWeightAddress;
    kn::FVector* value = func_0013f6e8(&result, &first, &second, &third, lastWeight, x, y, z);
    D_004f3770 = result;
    *position = D_004f3770;
    return value;
}
