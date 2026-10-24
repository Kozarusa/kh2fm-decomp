#include "../common/types.h"
extern "C" u32 D_0035f600;
extern "C" u32 D_0035f604;
extern "C" void func_00106420(u32*);

void func_002a76d8() {
    if (D_0035f600 != 0) {
        func_00106420((u32*)D_0035f600);
        D_0035f600 = 0;
    }
    u32 base = D_0035f604;
    if (base == 0) return;
    u32 cursor = base + 8720;
    for (;;) {
        if (base == cursor) break;
        cursor -= 436;
        u32 table = *(u32*)cursor;
        ((void (*)(u32))*(u32*)(table + 12))(cursor);
    }
    func_00106420((u32*)base);
    D_0035f604 = 0;
}
