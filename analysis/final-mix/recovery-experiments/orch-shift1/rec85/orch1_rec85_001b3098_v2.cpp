#include "../common/types.h"
struct Header {
    s32 pad;
    s32 count;
};
struct Owner {
    Header* header;
    u8* entries;
};
extern "C" u32 func_00165768(s32);
extern "C" u32 func_00105110(void*);

void func_001b3098(Owner* owner) {
    if (owner->header != 0) {
        s32 index = 0;
        if (owner->header->count > 0) {
            s32 offset = 0;
            do {
                index++;
                func_00165768(*(s32*)(owner->entries + offset + 0x80));
                offset += 0x90;
            } while (index < owner->header->count);
        }
        func_00105110(owner->entries);
        owner->header = 0;
    }
}

