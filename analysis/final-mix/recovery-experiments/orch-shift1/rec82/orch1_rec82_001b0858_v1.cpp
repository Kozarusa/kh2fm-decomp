#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_0036d974;
extern "C" f32 func_001b08e8(u8* object, const kn::FVector* input);
extern "C" u32 func_001ad990(f32, f32, f32, void*);

void func_001b0858(u8* object, const kn::FVector* input, s32 value, f32 scale) {
    if (*(s32*)(object + 12) >= 0) {
        *(s32*)(object + 4) = 3;
        func_001b08e8(object, input);
        func_001ad990(0.0f, D_0036d974, scale, object + 16);
        *(s32*)(object + 8) = value;
    }
}
