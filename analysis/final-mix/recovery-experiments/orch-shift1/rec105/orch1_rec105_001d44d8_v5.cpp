#include "../common/types.h"
extern "C" u8* D_01d5ba28;

u8* func_001d44d8(s32 id) {
    s32 index = 0;
    u8* head = *(u8* volatile*)&D_01d5ba28;
    if (0 < *(s32*)(head + 4)) {
        u8* base;
        do {
            base = *(u8* volatile*)&D_01d5ba28;
            u8* entry = base + index * 0x40;
            index = index + 1;
            if (*(u16*)(entry + 0x30) == id) {
                return entry + 8;
            }
        } while (index < *(s32*)(base + 4));
    }
    return 0;
}