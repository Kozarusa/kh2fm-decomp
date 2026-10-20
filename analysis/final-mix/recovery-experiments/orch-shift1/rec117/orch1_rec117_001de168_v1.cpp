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
    if (owner->header->count > 0) {
        u8* entry = owner->entries;
        do {
            index = index + 1;
            if (*(u16*)(entry + 2) == id) {
                return func_001ddef0(owner, entry);
            }
            entry = entry + 0x50;
        } while (index < owner->header->count);
    }
    return 0;
}
