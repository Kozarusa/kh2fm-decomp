#include "../common/types.h"
extern "C" u8* D_01c6cb98;

u8* func_001a82b0(u8* entry) {
    u8** table = &D_01c6cb98;
    if (entry == 0) {
        return *table + 4;
    }
    u8* next = entry + 12;
    if (next >= *table + *(u16*)(*table + 2) * 12 + 4) {
        next = 0;
    }
    return next;
}
