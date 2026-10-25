#include "../common/types.h"
extern "C" u8* D_01d5ba28;
extern "C" s32 func_001d3c78(u8*);

u8* func_001d3fe0(s32 id) {
    for (s32 index = 0; index < *(s32*)(D_01d5ba28 + 4); index++) {
        u8* entry = D_01d5ba28 + index * 64 + 8;
        if (func_001d3c78(entry) != 0 && *(u16*)(entry + 40) == id) {
            return entry;
        }
    }
    return 0;
}
