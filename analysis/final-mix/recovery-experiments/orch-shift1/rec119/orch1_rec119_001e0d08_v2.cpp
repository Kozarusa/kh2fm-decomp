#include "../common/types.h"
struct Entry { u8 pad[0x30]; f32 x; f32 y; f32 z; f32 w; };
struct Root { u8 pad[0xdc4]; Entry* table; };
struct Obj { u8 pad[0x20]; s32 index; };
extern "C" Root* D_00352bd0;

void func_001e0d08(Obj* object, f32* vec) {
    f32 x = vec[0];
    f32 y = vec[1];
    f32 z = vec[2];
    D_00352bd0->table[object->index].x = x;
    D_00352bd0->table[object->index].y = y;
    D_00352bd0->table[object->index].z = z;
}
