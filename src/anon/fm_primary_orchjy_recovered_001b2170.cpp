#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_00349e10;
// why: exact types of the accepted definition (fm_primary_orchiz_recovered_00184540.cpp); extern "C" so the isolated probe links (as in accepted 001a0a48)
extern "C" kn::FVector* func_00184540(kn::FVector* out, u8* object, f32 blend, f32 scale);

// why: handle is the unused second argument register (a1 is overwritten before the call), same shape as accepted 001a0a48

kn::FVector* func_001b2170(kn::FVector* destination, s32 handle, u8* object) {
    f32 blend = *(f32*)(object + 0xf0);
    f32 current = *(f32*)(object + 0x24);
    kn::FVector value;
    func_00184540(&value, object, blend, blend);
    *destination = value;
    f32 limit = *(f32*)(object + 0x120);
    f32 next = current + *(f32*)(object + 0xf4) * D_00349e10;
    f32 result;
    if (next < limit) {
        result = next;
    } else {
        result = limit;
    }
    *(f32*)(object + 0x24) = result;
    ((f32*)destination)[1] = result * D_00349e10;
    return destination;
}
