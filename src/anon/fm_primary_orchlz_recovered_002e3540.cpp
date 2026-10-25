#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" kn::FVector D_01e2be20;
extern "C" kn::FVector func_0016af58(u8*);
extern "C" s32 func_0016c028(s32);
extern "C" kn::FVector func_002cba88(f32, f32, u8*, s32, const kn::FVector&);

void func_002e3540(u8** object) {
    u8* pointer = *(u8**)(*object + 4);
    if (*(u8**)(pointer + 0x508) != 0) {
        D_01e2be20 = func_002cba88(*(f32*)(object + 1), 1.0f, *(u8**)(pointer + 0x508), func_0016c028((s32)pointer), func_0016af58(pointer));
        *object = (u8*)&D_01e2be20;
    }
}
