#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" u32 func_0013f888(...);
extern "C" u32 func_0013fca8(s32);
extern "C" u32 func_00159ce0(s32,s64);

void func_0015a528(s32 object) {
    kn::FVector* target = (kn::FVector*)(object + 0x80);
    kn::FVector saved = *target;
    kn::FVector result;
    func_00159ce0(object, (s64)&result);
    func_0013f888(object, &result, 0);
    *target = result;
    func_0013fca8(object);
    *target = saved;
}