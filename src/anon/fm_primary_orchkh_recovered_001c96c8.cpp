#include "../common/types.h"
#include "../kn/fvector.hpp"
// why: types copied from the accepted definition fm_primary_orchbd_recovered_0017c030.cpp, extern "C" added for the isolated probe link
extern "C" kn::FVector* func_0017c030(kn::FVector*, u8*, s32, u8);
// why: types copied from the accepted definition fm_primary_orchjw_recovered_0017c4c8.cpp, extern "C" added for the isolated probe link
extern "C" void func_0017c4c8(u8*, kn::FVector*);
// why: copied exactly from the accepted call site in fm_primary_animation_recovered.cpp (void, as the accepted definition fm_primary_orchbe_recovered_0017f488.cpp)
extern "C" void func_0017f488(f32, f32, s32, u32);

// why: void per DEVIATIONS #36; the only exit leaves v0 from the final call to func_0017f488, whose accepted definition is void (stale-b)
// why: the first parameter is never read (a0 is overwritten before use) but keeps object in a1 and flag in a2

void func_001c96c8(s32 unused, u8* object, u8 flag) {
    kn::FVector vector;
    kn::FVector copy;
    u32 output[4];
    kn::FVector* destination = &vector;
    asm("" : "+r"(destination)); // why: original forms the destination argument before the buffer argument
    // why: the accepted definition types the third argument as s32; the original passes a stack buffer address
    func_0017c030(destination, object, (s32)output, flag);
    if (*(u32*)(object + 268) & 0x10) {
        ((f32*)&vector)[3] = *(f32*)(*(u8**)(object + 300) + 36);
        // why: lq/sq copy primitive, same text as kn::FVector::operator= in kn/fvector.hpp without its self-check branch (an FVector assignment emitted beq, a Quad copy was reordered)
        asm("lq $8, 0(%1);" "sq $8, 0(%0);" : : "r"(&copy), "r"(&vector) : "t0");
        func_0017c4c8(object, &copy);
        object[1300] = 5;
    } else {
        // why: lq/sq copy primitive, same text as kn::FVector::operator= in kn/fvector.hpp without its self-check branch
        asm("lq $8, 0(%1);" "sq $8, 0(%0);" : : "r"(&copy), "r"(&vector) : "t0");
        func_0017c4c8(object, &copy);
    }
    func_0017f488(0.0f, 0.0f, (s32)(object + 320), output[0]);
    // why: written in reverse; the scheduler emits the 260 store first
    *(s32*)(object + 256) = 4;
    *(s32*)(object + 260) = 5;
}
