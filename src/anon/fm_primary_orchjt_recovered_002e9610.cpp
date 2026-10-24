#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" bool func_001dc9e0(...);
extern "C" u32 func_001dc5f8(...);

void func_002e9610(kn::FVector* object, kn::FVector* value) {
    u32 effect;
    object[0] = *value;
    object[2] = *value;
    effect = *(u32*)((u8*)object + 60);
    if (effect != 0) {
        if (func_001dc9e0(effect)) {
            *(kn::FVector*)func_001dc5f8(*(u32*)((u8*)object + 60)) = *value;
        }
    }
}
