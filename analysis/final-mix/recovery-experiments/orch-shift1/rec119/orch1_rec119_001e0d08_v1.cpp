#include "../common/types.h"
struct Inner { u8 pad[0xdc4]; u8* table; };
extern "C" Inner* volatile D_00352bd0;

void func_001e0d08(s32* object, f32* vec) {
    f32 x = vec[0];
    f32 y = vec[1];
    f32 z = vec[2];
    *(f32*)(D_00352bd0->table + object[8] * 0x40 + 0x30) = x;
    *(f32*)(D_00352bd0->table + object[8] * 0x40 + 0x34) = y;
    *(f32*)(D_00352bd0->table + object[8] * 0x40 + 0x38) = z;
}
