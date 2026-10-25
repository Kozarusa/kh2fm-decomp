#include "../common/types.h"
struct Header {
    s32 pad0;
    s32 pad4;
    s32 count;
};
struct Owner {
    Header* header;
    u8* entries;
};
extern "C" u64 func_001ddef0(...);

void func_001de228(Owner* owner, u32 kind, u32 first, u32 second, u32 third, u32 fourth) {
    s32 total = owner->header->count;
    if (total > 0) {
        s32 count = total; // why: original loads the count into t7 and copies it into the loop counter s0
        s32 offset = 0;
        do {
            u8* entry = owner->entries + offset;
            offset = offset + 0x50;
            if (entry[4] == kind) {
                func_001ddef0(owner, entry, first, second, third, fourth);
            }
            count = count - 1;
        } while (count != 0);
    }
}
