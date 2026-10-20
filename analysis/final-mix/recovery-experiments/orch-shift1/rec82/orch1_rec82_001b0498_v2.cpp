#include "../common/types.h"
struct Owner { u8 pad[352]; u32 flags; };
struct Object { Owner* owner; s32 unused; u8 flag; };

s32 func_001b0498(Object* object) {
    s32 result = 0;
    Owner* owner = object->owner;
    if (owner != 0) {
        if ((u8)((object->flag ^ 1) & 1) != 0) {
            result = 1;
        } else {
            u32 bits = owner->flags & 0x4000000;
            if (bits != 0) {
                result = 1;
            }
        }
    }
    return result;
}
