#include "../common/types.h"
extern "C" f32 D_00348d30[];

void func_001450e8(s16* source, s32 index, f32* result) {
    f32 last;
    if (index == 0) {
        result[0] = (f32)source[0];
        asm volatile("" ::: "memory"); // why: keeps store order (original loads each element after the previous store)
        result[1] = (f32)source[1];
        asm volatile("" ::: "memory"); // why: keeps store order (original loads each element after the previous store)
        result[2] = (f32)source[2];
        asm volatile("" ::: "memory"); // why: keeps store order (original loads each element after the previous store)
        result[3] = (f32)source[3];
        asm volatile("" ::: "memory"); // why: keeps store order (original loads each element after the previous store)
        result[4] = (f32)source[4];
        asm volatile("" ::: "memory"); // why: keeps store order (original loads each element after the previous store)
        last = (f32)source[5];
    } else {
        f32 scale = D_00348d30[index];
        result[0] = (f32)source[0] * scale;
        asm volatile("" ::: "memory"); // why: keeps store order (original loads each element after the previous store)
        result[1] = (f32)source[1] * scale;
        asm volatile("" ::: "memory"); // why: keeps store order (original loads each element after the previous store)
        result[2] = (f32)source[2] * scale;
        asm volatile("" ::: "memory"); // why: keeps store order (original loads each element after the previous store)
        result[3] = (f32)source[3] * scale;
        asm volatile("" ::: "memory"); // why: keeps store order (original loads each element after the previous store)
        result[4] = (f32)source[4] * scale;
        asm volatile("" ::: "memory"); // why: keeps store order (original loads each element after the previous store)
        last = (f32)source[5] * scale;
    }
    result[5] = last;
}
