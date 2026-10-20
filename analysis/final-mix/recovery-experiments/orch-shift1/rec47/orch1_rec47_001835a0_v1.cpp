#include "../common/types.h"

extern "C" bool func_0019c400(u8*);
extern "C" void func_0016ae58(u8*, f32);
extern "C" f32 func_0017ce10(f32);

void func_001835a0(u8* object, f32 delta) {
    if (func_0019c400(object)) {
        return;
    }
    func_0016ae58(object, *(f32*)(object + 0x55c) + delta);
    *(f32*)(object + 0x66c) = func_0017ce10(*(f32*)(object + 0x66c) + delta);
}