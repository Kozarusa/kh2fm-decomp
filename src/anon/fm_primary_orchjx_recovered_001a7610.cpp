#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" bool func_001d35e0(...);

// Preserve original registry aliases.
s32 func_001a7610(kn::FVector* position, kn::FVector* result, u32 mask, f32 height, f32 offset) asm("_Z13func_001a7610jjjff");

s32 func_001a7610(kn::FVector* position, kn::FVector* result, u32 mask, f32 height, f32 offset) {
    kn::FVector top;
    kn::FVector bottom;
    kn::FVector spare[2]; // why: unused 32-byte local keeps the original frame (hit at sp+64)
    kn::FVector hit[2]; // why: callee output block is 32 bytes (frame saves start at sp+96)
    kn::FVector* low = &bottom; // why: original forms &bottom (a2) before the first copy
    kn::FVector* out = hit; // why: original forms &hit early in s2, result stays in s1
    top = *position;
    ((f32*)&top)[1] = ((f32*)&top)[1] - offset;
    *low = *position;
    ((f32*)low)[1] = ((f32*)low)[1] + (height + offset);
    if (func_001d35e0(out, &top, low, mask)) {
        *result = *out;
        return 1;
    }
    *result = *position;
    return 0;
}
