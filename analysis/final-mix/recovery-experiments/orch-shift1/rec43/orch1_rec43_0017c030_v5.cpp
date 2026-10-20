#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 func_0016c460(s32, s32);

kn::FVector* func_0017c030(kn::FVector* destination, u8* object, s32 argument, u8 flag) {
    *destination = *(kn::FVector*)(object + 0x10);
    ((f32*)destination)[1] = func_0016c460((s32)object, argument);
    if (flag != 0) {
        *(u32*)(object + 0x108) = *(u32*)(object + 0x108) | 0x10000;
    }
    return destination;
}