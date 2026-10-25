#include "../common/types.h"
struct Info {
    u8 pad[2];
    u8 type;
    u8 flags;
    u8 pad2[14];
    u16 index;
};
extern "C" u8 D_0032e020[];
extern "C" u32 func_001a80c8(...);  // copied from accepted fm_primary_addresspair_recovered_001a6c60.cpp

void func_001a34e0(u32 id, s32 amount) {
    Info* info = (Info*)func_001a80c8(id);
    u8* base = D_0032e020;
    u32 flags = info->flags;
    u32 locked = flags & 1;
    if (locked != 0) {
        u32 index = info->index;
        u32* bits = (u32*)(base + 4560);
        bits[index >> 5] &= ~(1 << (index & 31));
        return;
    }
    u8* count = base + info->index + 4240;
    if (amount < *count) {
        *count = *count - amount;
    } else {
        *count = 0;
    }
}
