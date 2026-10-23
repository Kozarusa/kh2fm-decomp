#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" f32 func_001906f0(u32 source, Quad* input);

f32 func_002e7ff8(u32* object) {
    Quad packet;
    // why: original copies the quad through t0 ($8)
    register Quad temp asm("$8") = *(Quad*)object[1];
    packet = temp;
    asm volatile("" ::: "memory"); // why: keeps store order
    f32 result = func_001906f0(object[0], &packet);
    *(f32*)object = result;
    return result; // R4.3: callee $f0 is still live at the epilogue
}
