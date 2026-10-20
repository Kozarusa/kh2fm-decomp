#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" f32 D_0036e7e8;
extern "C" f32* func_001dc670();

void func_001dcb98(u32 unused, u8* bytes) {
    f32 color[4] __attribute__((aligned(16)));
    f32* cursor = color;
    s32 index = 0;
    do {
        u8* source = bytes + index;
        index = index + 1;
        *cursor = (f32)*source * D_0036e7e8;
        cursor = cursor + 1;
    } while (index < 4);
    f32* destination = func_001dc670();
    if (destination != color) {
        *(Quad*)destination = *(Quad*)color; // why: keeps lq/sq copy
    }
}