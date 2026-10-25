#include "../common/types.h"
struct Object;
typedef s32 (*ObjectMethod)(Object*);
struct Object {
    ObjectMethod* vtable;
    u8 pad0[0x108];
    u32 flags;
    u8 pad1[0x478];
    u32 state;
    u8 pad2[0x328];
    Object* next;
};
extern "C" Object* D_01d48da0;

void func_001b9f80(s32 limit) {
    Object* object = 0;
    Object* next;
    // why: statement expression with goto keeps the advance arm out of line,
    // which makes the compiler emit the original branch-likely (bnezl) head (sibling 002bc708)
    while (({
        if (object != 0) goto advance;
        next = D_01d48da0;
        goto done;
    advance:
        next = object->next;
    done:
        object = next;
        next != 0;
    })) {
        if ((next->state & 0x20) == 0 && next->vtable[15](next) < limit) {
            next->flags &= ~0x80;
        }
    }
}
