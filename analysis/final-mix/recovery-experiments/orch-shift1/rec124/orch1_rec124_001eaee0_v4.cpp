#include "../common/types.h"

struct Offset {
    u8 pad0[12];
    s32* offset;
};

struct Dest {
    u8 pad[64];
    f32 x;
    f32 y;
    f32 z;
};

extern "C" Dest* volatile D_01d9e6e8;
extern "C" void func_002f4000(void*);

void func_001eaee0(u8* object, s32 unused, Offset* offset) {
    f32* source = (f32*)(object + *offset->offset + 160);
    func_002f4000((u8*)D_01d9e6e8 + 16);
    D_01d9e6e8->x = source[0];
    D_01d9e6e8->y = source[1];
    D_01d9e6e8->z = source[2];
}
