#include "../common/types.h"
struct Owner { u8 pad[352]; u32 flags; };
struct Object { Owner* owner; s32 unused; volatile u8 flag; };

s32 func_001b0498(Object* object) {
    if (object->owner != 0) {
        if ((u8)((object->flag ^ 1) & 1) != 0) { // why: volatile byte read to keep branch-likely layout
            return 1;
        }
        if ((object->owner->flags & 0x4000000) != 0) {
            return 1;
        }
    }
    return 0;
}
