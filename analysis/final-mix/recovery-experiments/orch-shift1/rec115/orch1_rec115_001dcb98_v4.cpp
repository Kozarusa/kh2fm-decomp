#include "../common/types.h"
struct Color4 {
    f32 values[4];
} __attribute__((aligned(16)));
extern "C" f32 D_0036e7e8;
extern "C" Color4* func_001dc670();

void func_001dcb98(u32 unused, u8* bytes) {
    f32 scale = D_0036e7e8;
    Color4 color;
    f32* cursor = color.values;
    s32 index = 0;
    do {
        u8* source = bytes + index;
        index = index + 1;
        *cursor = (f32)*source * scale;
        cursor = cursor + 1;
    } while (index < 4);
    Color4* destination = func_001dc670();
    if (destination != &color) {
        *destination = color;
    }
}