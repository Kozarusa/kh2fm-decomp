#include "../common/types.h"
extern "C" u8* D_01c6cb98;

u8* func_001a82b0(u8* entry) {
    if (entry == 0) {
        return D_01c6cb98 + 4;
    }
    u8* next = entry + 12;
    if (next >= D_01c6cb98 + *(u16*)(D_01c6cb98 + 2) * 12 + 4) {
        next = 0;
    }
    return next;
}