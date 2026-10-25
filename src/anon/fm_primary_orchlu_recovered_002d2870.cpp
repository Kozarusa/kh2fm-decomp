#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" u32 func_002d1260(void);
extern "C" u32 func_002d5c40(s32);
extern "C" kn::FVector func_002d3fa8(u32, s32);

kn::FVector func_002d2870(u8* object, s32 arg) {
    kn::FVector result;
    // why: the original stores the zero from a float register (mtc1 zero,$f0 then swc1); writing the 0.0f literal into each field (v1) compiled to sw zero stores and differed by 27 words
    f32 zero = 0.0f;
    *(f32*)&result.x = zero;
    *(f32*)&result.y = zero;
    *(f32*)&result.z = zero;
    *(f32*)&result.w = zero;
    u32 player = func_002d1260();
    if (func_002d5c40(player) == 2) {
        result = func_002d3fa8(*(u32*)(object + 324), arg);
    }
    return result;
}
