#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" kn::FVector D_004f37c0;
extern "C" kn::FVector D_004f37d0;
extern "C" kn::FVector D_004f37e0;
extern "C" f32 D_0036b414;
extern "C" f32 D_0036b418;
extern "C" f32 D_0036b41c;
extern "C" f32 D_0036b420;
extern "C" kn::FVector* func_0013f6e8(kn::FVector* out, kn::FVector* first, kn::FVector* second, kn::FVector* third, f32 weight, f32 x, f32 y, f32 z);

kn::FVector* func_0015d208(f32* first, f32* second) {
    kn::FVector result;
    kn::FVector a;
    kn::FVector b;
    kn::FVector c;
    kn::FVector* origin = &D_004f37c0;
    asm("" : "+r"(origin)); // why: keeps the address of D_004f37c0 in a register
    kn::FVector* center = &D_004f37d0;
    asm("" : "+r"(center)); // why: keeps the address of D_004f37d0 in a register
    *(f32*)&D_004f37d0.x = *first;
    *(f32*)&center->y = *second;
    asm("lq $8, 0(%1); sq $8, 0(%0)" : : "r"(&a), "r"(origin) : "$8"); // why: lq/sq copy primitive, plain copy failed (v2)
    asm("lq $8, 0(%1); sq $8, 0(%0)" : : "r"(&b), "r"(center) : "$8"); // why: lq/sq copy primitive, plain copy failed (v2)
    asm("lq $8, 0(%1); sq $8, 0(%0)" : : "r"(&c), "r"(&D_004f37e0) : "$8"); // why: lq/sq copy primitive, plain copy failed (v2)
    register f32* scale asm("$15") = &D_0036b414; // why: original forms each address in t7
    asm("" : "+r"(scale)); // why: original loads through the formed address
    f32 x = *scale;
    scale = &D_0036b418;
    asm("" : "+r"(scale)); // why: original loads through the formed address
    f32 y = *scale;
    scale = &D_0036b41c;
    asm("" : "+r"(scale)); // why: original loads through the formed address
    f32 z = *scale;
    scale = &D_0036b420;
    asm("" : "+r"(scale)); // why: original loads through the formed address
    f32 w = *scale;
    kn::FVector* value = func_0013f6e8(&result, &a, &b, &c, x, y, z, w);
    if (&result != origin) {
        asm("lq $8, 0(%1); sq $8, 0(%0)" : : "r"(origin), "r"(&result) : "$8"); // why: lq/sq copy primitive, plain copy failed (v2)
    }
    *first = *(f32*)&D_004f37c0.x;
    *second = *(f32*)&origin->y;
    return value;
}
