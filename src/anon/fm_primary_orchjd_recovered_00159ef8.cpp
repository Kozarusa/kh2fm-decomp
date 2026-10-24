#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" kn::FVector D_0034aa50[2];
extern "C" kn::FVector* func_0016c028(s32);

kn::FVector* func_00159ef8(u8* object) {
    kn::FVector* source = (kn::FVector*)(object + 0x80);
    // why: original keeps the func_0016c028 result in v0 for the copy and the return
    register kn::FVector* result asm("$2") = func_0016c028(*(s32*)(object + 0x44));
    D_0034aa50[0] = *source;
    D_0034aa50[1] = *result;
    return result;
}
