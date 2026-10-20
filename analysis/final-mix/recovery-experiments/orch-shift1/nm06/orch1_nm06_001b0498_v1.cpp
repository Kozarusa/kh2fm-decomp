#include "../common/types.h"
struct Owner { u8 pad[352]; u32 flags; };
struct Object { Owner* owner; s32 unused; u8 flag; };

s32 func_001b0498(Object* object) {
    s32 result = 1;
    if (object->owner == 0) {
        result = 0;
    } else if ((u8)((object->flag ^ 1) & 1) == 0) {
        if ((object->owner->flags & 0x4000000) == 0) {
            result = 0;
        }
    }
    return result;
}
