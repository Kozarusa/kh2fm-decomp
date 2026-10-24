#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u32 func_001b2210(u32, Quad*, f32, f32);
extern "C" u32 func_0016bd60(u64,u64);

u32 func_002e8390(u32* object) {
    register Quad* source asm("$15") = (Quad*)object[1]; // why: original loads the source pointer into t7
    register Quad temp asm("$8") = *source; // why: original moves the quad through t0
    Quad copy = temp;
    asm volatile("" ::: "memory"); // why: keeps store order
    register u32* first asm("$14") = (u32*)object[0]; // why: original keeps the first object pointer in t6
    func_001b2210(first[1], &copy, *(f32*)(object + 2), *(f32*)(object + 3));
    u32* second = (u32*)object[0];
    return func_0016bd60((s32)second[1], 9);
}
