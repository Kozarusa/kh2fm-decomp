#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" kn::FVector D_01e2c0c0;
extern "C" u64 func_0010c7e8(u32);
extern "C" kn::FVector* func_0011a900(kn::FVector*, u64);

kn::FVector* func_002f07f8(u32* object) {
    kn::FVector local;
    kn::FVector* result = func_0011a900(&local, func_0010c7e8(*(u32*)(object[0] + 4)));
    D_01e2c0c0 = local;
    object[0] = (u32)&D_01e2c0c0;
    return result;
}
