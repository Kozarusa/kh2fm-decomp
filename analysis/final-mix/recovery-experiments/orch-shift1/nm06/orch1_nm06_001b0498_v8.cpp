#include "../common/types.h"
struct Owner { u8 pad[352]; u32 flags; };
struct Object { Owner* owner; s32 unused; u8 flag; };

s32 func_001b0498(Object* object) {
    Owner* owner = object->owner;
    if (owner != 0) {
        if ((u8)((object->flag ^ 1) & 1) != 0) {
            return 1;
        }
        // why: volatile read changes the branch shape toward branch-likely
        if ((*(volatile u32*)&owner->flags & 0x4000000) != 0) {
            return 1;
        }
    }
    return 0;
}
