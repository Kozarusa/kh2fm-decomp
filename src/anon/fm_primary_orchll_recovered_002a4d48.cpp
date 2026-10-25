#include "../common/types.h"
extern "C" u32 D_0035f5ec;
extern "C" u32 D_0035f5f0;
extern "C" u32 D_00347f80;
extern "C" void func_00106420(u32*);

void func_002a4d48() {
    if (D_0035f5ec != 0) {
        func_00106420((u32*)D_0035f5ec);
        D_0035f5ec = 0;
    }
    if (D_0035f5f0 == 0) return;
    u32 cursor = D_0035f5f0 + *(u32*)(D_0035f5f0 - 4) * 436;
    for (;;) {
        if (D_0035f5f0 == cursor) break;
        cursor -= 436;
        u32 table = *(u32*)cursor;
        ((void (*)(u32))*(u32*)(table + 12))(cursor);
    }
    u32 heap = *(u32*)(D_00347f80 + 20);
    u32 table = *(u32*)heap;
    ((void (*)(u32, u32))*(u32*)(table + 4))(heap, D_0035f5f0 - 4);
    D_0035f5f0 = 0;
}
