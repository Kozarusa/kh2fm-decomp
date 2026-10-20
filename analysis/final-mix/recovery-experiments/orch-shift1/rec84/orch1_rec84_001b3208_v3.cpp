#include "../common/types.h"
struct Owner {
    s32 header;
    s32 entries;
};

void func_001b3208(Owner* owner, s32 key) {
    s32 header = owner->header;
    s32 index = 0;
    if (*(s32*)(header + 4) > 0) {
        s32 offset = 0;
        do {
            s32 scaled = index * 8;
            index++;
            if (*(s32*)(scaled + header + 8) == key) {
                s32 item = *(s32*)(offset + owner->entries + 128);
                *(u32*)(item + 8) = *(u32*)(item + 8) | 2;
                header = owner->header;
            }
            offset += 144;
        } while (index < *(s32*)(header + 4));
    }
}
