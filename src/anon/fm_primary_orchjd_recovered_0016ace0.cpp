#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_0036c1b4;
extern "C" u32 func_001ba028(...);
extern "C" u32 func_00193608(u8*);

// Preserve original registry aliases.
u32 func_0016ace0(u8* object, const kn::FVector& vector) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");

u32 func_0016ace0(u8* object, const kn::FVector& vector) {
    func_001ba028(object);
    *(kn::FVector*)(object + 0x540) = vector;
    f32* scale = &D_0036c1b4;
    asm("" : "+r"(scale)); // why: original materializes the address with addiu and loads at offset 0
    *(f32*)(object + 0x54c) = *scale;
    return func_00193608(object);
}
