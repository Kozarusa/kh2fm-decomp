#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Vec { f32 x, y, z, w; };
struct Obj { Vec pos; u8 pad[0x18]; u32 flags; u8 pad2[0x20]; f32* ref; };
extern "C" s32 func_001a4ff8(s32, Vec*);

s32 func_001c7950(Obj* object, s32 other) {
    if ((object->flags & 1) == 0) {
        return 0;
    }
    Vec local;
    // why: original copies the quad through t0 (register 8)
    register Quad copy asm("$8") = *(Quad*)&object->pos;
    *(Quad*)&local = copy;
    // why: keeps store order
    asm volatile("" ::: "memory");
    local.y = local.y + object->ref[1];
    return func_001a4ff8(other, &local);
}
