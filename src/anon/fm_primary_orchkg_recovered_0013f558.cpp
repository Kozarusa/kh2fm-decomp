#include "../common/types.h"
extern "C" f32 func_0013fd10(u8*);
extern "C" void func_0013f828(u32);
extern "C" u32 func_0013f888(...);
extern "C" void func_0013f5f0(u8*);
extern "C" u32 func_0013f608(...);
extern "C" u32 func_0013f648(...);

u32 func_0013f558(u8* object) {
    object[57] = 0;
    object[58] = 1;
    object[56] = 0;
    object[59] = 0;
    // why: VU macro store of the vf0 constant (0,0,0,1), same sqc2 $vf0 form as accepted fm_primary_orchjq_recovered_0019bfd0.cpp
    asm volatile("sqc2 $vf0,0(%0)" : : "r"(object + 160) : "memory");
    *(u32*)(object + 52) = 0;
    if (*(u32*)(object + 68) != 0) {
        f32 value = func_0013fd10(object);
        *(f32*)(object + 80) = value;
        *(f32*)(object + 76) = value;
        func_0013f828((u32)object);
        func_0013f888(object, object + 128, 0);
        func_0013f5f0(object);
        func_0013f608(object);
        return func_0013f648(object);
    }
    // why: the skip exit leaves the caller's entry v0 untouched; the original computes no value on this path
}
