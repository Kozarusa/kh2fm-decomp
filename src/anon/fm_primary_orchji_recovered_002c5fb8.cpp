#include "../common/types.h"
extern "C" u64 func_0016bda8(...);
extern "C" f32 D_00375758[];

u8* func_002c5fb8(u8* object) {
    func_0016bda8(object);
    f32* constant = D_00375758;
    // why: keeps the address materialized before the load, as in the original
    asm("" : "+r"(constant));
    register f32 increment asm("$f1") = *constant; // why: original loads the increment into f1
    *(f32*)(object + 8) = *(f32*)(object + 8) + increment;
    return object;
}
