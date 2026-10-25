#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" kn::FVector func_0019fbe0();
extern "C" s32 func_001b2d10(u32, kn::FVector*);

typedef void (*Handler)(u8*, u32);

kn::FVector* func_001c8fe8(kn::FVector* result, u8* object, u32 target) {
    // why: unused block-mode local reserves the 16-byte slot at sp+0 the original frame keeps below the call temporary
    kn::FVector scratch[1];
    *result = func_0019fbe0();
    if (0.0f < *(f32*)&result->y && func_001b2d10(target, result) != 0) {
        (*(Handler*)(*(u8**)object + 0x14))(object, target);
    }
    return result;
}
