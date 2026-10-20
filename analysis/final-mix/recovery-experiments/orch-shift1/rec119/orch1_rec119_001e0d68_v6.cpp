#include "../common/types.h"
union Word { s32 i; f32 f; Word* p; };
extern "C" Word D_00352bd0;

void func_001e0d68(Word* object, f32* vec) {
    ((Word*)((u8*)D_00352bd0.p[0xdc4 / 4].p + object[8].i * 0x40))[8].f = vec[0];
    ((Word*)((u8*)D_00352bd0.p[0xdc4 / 4].p + object[8].i * 0x40))[9].f = vec[1];
    ((Word*)((u8*)D_00352bd0.p[0xdc4 / 4].p + object[8].i * 0x40))[10].f = vec[2];
}
