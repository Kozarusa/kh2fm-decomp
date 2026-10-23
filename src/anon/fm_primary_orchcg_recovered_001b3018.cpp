#include "../common/types.h"
struct Header {
    s32 pad;
    s32 count;
};
struct Owner {
    Header* header;
    s32 entries;
};
extern "C" u32 func_00105110(u64);
extern "C" u32 func_00165768(s32);

void func_001b3018(Owner* owner) {
    if (owner->header != 0) {
        s32 index = 0;
        if (owner->header->count > 0) {
            s32 offset = 0;
            do {
                index++;
                s32 address = offset + owner->entries;
                func_00165768(*(s32*)(address + 128));
                offset += 144;
            } while (index < owner->header->count);
        }
        func_00105110((u64)owner->entries);
        owner->header = 0;
    }
}
