#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" f32 D_0036e7e8;
extern "C" f32* func_001dc670();

f32* func_001dcb98(u32 unused, u8* bytes) {
    f32 color[4] __attribute__((aligned(16)));
    f32* scalePointer = &D_0036e7e8;
    s32 index = 0;
    f32* cursor = color;
    asm volatile("" : "+r"(scalePointer)); // why: original keeps the global address in a register and loads it after the loop setup
    f32 scale = *scalePointer;
    do {
        u8* source = bytes + index;
        index = index + 1;
        *cursor = (f32)*source * scale;
        cursor = cursor + 1;
    } while (index < 4);
    f32* destination = func_001dc670();
    if (destination != color) {
        register Quad value asm("$8") = *(volatile Quad*)color; // why: original copies through t0
        *(Quad*)destination = value;
    }
    return destination;
}
