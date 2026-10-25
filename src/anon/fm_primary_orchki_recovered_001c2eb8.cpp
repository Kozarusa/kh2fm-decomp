#include "../common/types.h"
extern "C" u8* D_01d4955c;
extern "C" void func_001c2d88(u8*);

// Preserve original registry aliases.
void func_001c2eb8(u32 id) asm("_Z16u_call4_001c2eb8jjjj");

void func_001c2eb8(u32 id) {
    u8* table = D_01d4955c;
    s32 count = *(s32*)(table + 4);
    u16* cursor = (u16*)(table + 8);
    u16* found;
    for (s32 index = 0; index < count; index++) {
        u16 value = *cursor;
        found = cursor;
        if (value == id) {
            // why: the match leaves the search with found set, skipping the not-found reset as the original branch does
            goto search_done;
        }
        cursor += 0x40;
    }
    found = 0;
search_done:
    u16* entry = found;
    if (entry < (u16*)(D_01d4955c + *(s32*)(D_01d4955c + 4) * 0x80 + 8)) {
        while (*entry == id) {
            func_001c2d88((u8*)entry);
            entry += 0x40;
            if (entry >= (u16*)(D_01d4955c + *(s32*)(D_01d4955c + 4) * 0x80 + 8)) {
                return;
            }
        }
    }
}
