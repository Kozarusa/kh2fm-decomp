#include "../common/types.h"
union Word { s32 i; f32 f; Word* p; };
extern "C" Word D_00352bd0;

void func_001e0d68(Word* object, f32* vec) {
    f32 x = vec[0];
    f32 y = vec[1];
    f32 z = vec[2];
    ((Word*)(object[8].i * 0x40 + (s32)D_00352bd0.p[0xdc4 / 4].p))[8].f = x;
    ((Word*)(object[8].i * 0x40 + (s32)D_00352bd0.p[0xdc4 / 4].p))[9].f = y;
    ((Word*)(object[8].i * 0x40 + (s32)D_00352bd0.p[0xdc4 / 4].p))[10].f = z;
}
