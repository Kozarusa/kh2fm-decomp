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

u32 func_00147240(f32 threshold, Subject* subjectArg, Other* otherArg) {
    // why: original keeps other in s0 and subject in s1
    register Other* other asm("$16") = otherArg;
    // why: subject bound to s1 as in the original
    register Subject* subject asm("$17") = subjectArg;
    bool busy = func_00228378(subject);
    u32 result = 0;
    if (!busy) {
        if (subject->active != 0) {
            if ((other->flags & 1) == 1) {
                result = 1;
                if (!(threshold < subject->limit)) {
                    result = 0;
                }
            }
        }
    }
    return result;
}
