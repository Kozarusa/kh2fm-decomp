#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" s32 func_001de2e0(u32, s32);
extern "C" u32 func_001de168(u32, s32, s32, s32, s32, s32);
extern "C" kn::FVector* func_001dc5f8(u32);

u32 func_001a3b48(u32 pax, s32 id, kn::FVector* position, s32 first, s32 second, s32 third) {
    s32 index = func_001de2e0(pax, id);
    if (index < 0) {
        return 0;
    }
    u32 effect = func_001de168(pax, index, first, second, third, 0);
    if (effect != 0) {
        *func_001dc5f8(effect) = *position;
    }
    return effect;
}
