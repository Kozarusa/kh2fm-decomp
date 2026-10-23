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
extern "C" u64 func_001ddef0(Owner* owner, u8* entry);

u64 func_001de168(Owner* owner, u32 id) {
    s32 index = 0;
    s32 count = owner->header->count;
    u64 result = 0;
    if (count > 0) {
        u8* entry = owner->entries;
        do {
            if (*(u16*)(entry + 2) == id) {
                result = func_001ddef0(owner, entry);
                break;
            }
            index = index + 1;
            entry = entry + 0x50;
        } while (index < count);
    }
    return result;
}
