#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" u32 func_001780d8(...);
extern "C" u32 func_00198860(u64, u64);
extern "C" u32 func_0017a7d8(...);

void func_002dd730(u8* object) {
    func_001780d8();
    func_00198860((u64)object, 8);
    *(kn::FVector*)(object + 0xbf0) = *(kn::FVector*)(object + 0x540);
    func_0017a7d8(object);
    *(f32*)(object + 0xc00) = 1.0f;
}
