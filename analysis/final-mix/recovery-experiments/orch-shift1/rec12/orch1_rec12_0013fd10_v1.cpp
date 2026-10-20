#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" void func_0016af58(kn::FVector*, s32);
extern "C" void func_0013fcd8(u8*, kn::FVector*);

void func_0013fd10(u8* object) {
    kn::FVector first;
    kn::FVector second;
    func_0016af58(&second, *(s32*)(object + 0x44));
    first = second;
    second = first;
    func_0013fcd8(object, &second);
}
