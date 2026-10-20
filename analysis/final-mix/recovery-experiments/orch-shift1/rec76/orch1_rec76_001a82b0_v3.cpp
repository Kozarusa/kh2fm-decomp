#include "../common/types.h"
extern "C" u8* D_01c6cb98;

u8* func_001a82b0(u8* entry) {
    if (entry == 0) {
        return D_01c6cb98 + 4;
    }
    s32 stride = 12;
    u8* base = D_01c6cb98;
    u32 count = *(u16*)(base + 2);
    u8* next = entry + stride;
    if (next >= base + count * stride + 4) {
        next = 0;
    }
    return next;
}