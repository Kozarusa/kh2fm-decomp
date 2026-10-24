#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_00349e10;
extern "C" f32 D_0036d448;
extern "C" f32 D_0036d44c;
// why: exact types of the accepted definition (fm_primary_orchiz_recovered_00184540.cpp); extern "C" so the isolated probe links
extern "C" kn::FVector* func_00184540(kn::FVector* out, u8* object, f32 blend, f32 scale);
extern "C" f32 func_0017c930(s32, u8*);
extern "C" u32 func_00180618(u8*);

kn::FVector* func_001a0a48(kn::FVector* destination, s32 handle, u8* object) {
    register f32 current asm("$f1") = *(f32*)(object + 0xd0); // why: original loads the current value into f1 and the limit into f0
    f32 next = current + D_00349e10;
    if (next < *(f32*)(object + 0xd4)) {
        *(f32*)(object + 0xd0) = next;
        ((f32*)destination)[1] = func_0017c930(handle, object);
        f32 zero = 0.0f;
        asm("" : "+f"(zero)); // why: original stores the zero from an FPR (mtc1 + swc1), not sw zero
        ((f32*)destination)[2] = zero;
        ((f32*)destination)[0] = zero;
        return destination;
    }
    f32* address = &D_0036d448;
    asm("" : "+r"(address)); // why: original forms the full address before the lwc1
    f32 blend = *address;
    address = &D_0036d44c;
    asm("" : "+r"(address)); // why: original forms the full address before the lwc1
    kn::FVector value;
    func_00184540(&value, object, blend, *address);
    *destination = value;
    u8* motion = object + 320;
    if (*(s32*)(motion + 20) == 156) {
        if (func_00180618(motion) == 0) {
            ((s32*)destination)[1] = 0;
            return destination;
        }
    }
    *(f32*)(object + 0xd0) = next;
    ((f32*)destination)[1] = func_0017c930(handle, object);
    return destination;
}
