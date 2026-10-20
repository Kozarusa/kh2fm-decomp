#include "../common/types.h"

struct Offset {
    u8 pad0[12];
    s32* offset;
};

struct Vec {
    f32 x;
    f32 y;
    f32 z;
};

extern "C" u8* volatile D_01d9e6e8;
extern "C" void func_002f4000(u8*);

void func_001eaee0(u8* object, s32 unused, Offset* offset) {
    f32* source = (f32*)(object + *offset->offset + 160);
    func_002f4000(D_01d9e6e8 + 16);
    *(f32*)(D_01d9e6e8 + 64) = source[0];
    *(f32*)(D_01d9e6e8 + 68) = source[1];
    *(f32*)(D_01d9e6e8 + 72) = source[2];
}
