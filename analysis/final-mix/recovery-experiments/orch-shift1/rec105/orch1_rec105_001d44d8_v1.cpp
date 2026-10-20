#include "../common/types.h"
extern "C" u8* D_01d5ba28;

u8* func_001d44d8(s32 id) {
    s32 index = 0;
    if (0 < *(s32*)(D_01d5ba28 + 4)) {
        do {
            u8* entry = D_01d5ba28 + index * 0x40;
            index = index + 1;
            if (*(u16*)(entry + 0x30) == id) {
                return entry + 8;
            }
        } while (index < *(s32*)(D_01d5ba28 + 4));
    }
    return 0;
}