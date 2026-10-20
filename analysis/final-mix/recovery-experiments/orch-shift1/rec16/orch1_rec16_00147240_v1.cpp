#include "../common/types.h"
extern "C" bool func_00228378(...);

struct Subject {
    u8 pad0[0x774];
    f32 limit;
    u8 active;
};

struct Other {
    u8 pad0[0xf8];
    u32 flags;
};

u32 func_00147240(f32 threshold, Subject* subject, Other* other) {
    u32 result = 0;
    if (func_00228378(subject) == 0) {
        if (subject->active != 0) {
            if ((other->flags & 1) != 0) {
                result = 1;
                if (!(threshold < subject->limit)) {
                    result = 0;
                }
            }
        }
    }
    return result;
}
