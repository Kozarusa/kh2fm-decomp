#include "../common/types.h"
union Word { s32 i; f32 f; struct Ent* p; };
struct Ent { Word w[16]; };
extern "C" Word D_00352bd0;

void func_001e0d68(Word* object, f32* vec) {
    f32 x = vec[0];
    f32 y = vec[1];
    f32 z = vec[2];
    ((Word*)D_00352bd0.p)[0xdc4 / 4].p[object[8].i].w[8].f = x;
    ((Word*)D_00352bd0.p)[0xdc4 / 4].p[object[8].i].w[9].f = y;
    ((Word*)D_00352bd0.p)[0xdc4 / 4].p[object[8].i].w[10].f = z;
}
