#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_00349e10;
extern "C" kn::FVector func_00184540(u8*);
extern "C" f32 func_0017c930(s32, u8*);

kn::FVector* func_0017c870(kn::FVector* destination, s32 handle, u8* object) {
    *(s32*)(object + 0x14) = 0;
    f32 delta = D_00349e10;
    *(f32*)(object + 0xd0) = *(f32*)(object + 0xd0) + delta;
    kn::FVector value = func_00184540(object);
    *destination = value;
    ((f32*)destination)[1] = func_0017c930(handle, object);
    return destination;
}