#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" void func_001391a8(u8*, kn::FVector*);
extern "C" s32 func_00139d78(u8*);

void func_0013e3b0(u8* object, kn::FVector* source) {
    kn::FVector copy;
    copy = *source;
    u8* inner = object + 0x1c0;
    func_001391a8(object, &copy);
    if (func_00139d78(inner)) {
        copy = *source;
        func_001391a8(inner, &copy);
    }
}
