#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" void func_0016af58(kn::FVector*, s32);
extern "C" void func_0013fcd8(u8*, kn::FVector*);

void func_0013fd10(u8* object) {
    kn::FVector first;
    kn::FVector second;
    // why: binding an output to s2 reproduces the original's unused s2 save without emitting an instruction
    register u32 spare asm("$18");
    asm("" : "=r"(spare));
    func_0016af58(&second, *(s32*)(object + 0x44));
    first = second;
    // why: unguarded aligned 128-bit copy through t0; the original has no self-assignment test here
    asm volatile("lq $8,0(%1); sq $8,0(%0)" : : "r"(&second), "r"(&first) : "$8", "memory");
    func_0013fcd8(object, &second);
}
