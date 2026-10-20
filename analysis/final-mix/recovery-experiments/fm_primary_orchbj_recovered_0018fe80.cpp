#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" u32 func_001b58f0(u32, u32, u32, u32);
extern "C" kn::FVector* func_001dc5f8(u32);

void func_0018fe80(u32* object) {
    u32 result = func_001b58f0(object[0], object[1], object[3], 0);
    if (result != 0) {
        kn::FVector* target = func_001dc5f8(result);
        *target = *(kn::FVector*)object[2];
    }
    object[0] = result;
}
