#include "../common/types.h"
extern "C" u8* D_01c6cb98;

u8* func_001a82b0(u8* entry) {
    if (entry == 0) {
        return D_01c6cb98 + 4;
    }
    // why: volatile read keeps the table load after the stride constant like the original
    u8* table = *(u8* volatile*)&D_01c6cb98;
    u8* next = entry + 12;
    if (next >= table + *(u16*)(table + 2) * 12 + 4) {
        next = 0;
    }
    return next;
}
