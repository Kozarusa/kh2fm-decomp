#include "../common/types.h"
extern "C" u16 func_0011c228(u8*);
extern "C" s32 func_0011c230(u8*);
extern "C" void func_0016c698(s32, u32, u8*);
struct IdList {
    u8 header[8];
    u16 ids[16];
};
struct EntryFlags {
    u8 header[16];
    u32 active : 1;
};

s32 func_00180a10(u8* object, u8* entry) {
    u16 saved[16];
    s32 count = *(s32*)(object + 0x1b8);
    s32 copied = 0;
    if (count > 0) {
        u16* source = (u16*)(object + 0x198);
        do {
            saved[copied] = *source++;
        } while (++copied < count);
    }
    *(s32*)(object + 0x1b8) = 0;
    s32 result;
    while ((result = func_0011c230(entry)) == 0) {
        if ((u8)((EntryFlags*)entry)->active) {
            u16 id = func_0011c228(entry);
            s32 index = *(s32*)(object + 0x1b8);
            *(s32*)(object + 0x1b8) = index + 1;
            ((IdList*)((u8*)((u16*)object + index) + 0x190))->ids[0] = id;
            for (s32 i = 0; i < count; i++) {
                if (saved[i] == id) {
                    goto next;
                }
            }
            func_0016c698(*(s32*)(object + 8), id, entry);
        }
    next:
        entry += 0x20;
    }
    return result;
}
