#include "../common/types.h"
extern "C" u32 D_0035f5f4;
extern "C" u32 D_0035f5f8;
extern "C" u8 D_0035f5fc;
extern "C" u8 D_0035f5fd;
extern "C" void func_00106420(u32*);

void func_002a6970() {
    u32 base = D_0035f5f4;
    if (base != 0) {
        u32 cursor = base + 3488;
        for (;;) {
            if (base == cursor) break;
            cursor -= 436;
            u32 table = *(u32*)cursor;
            ((void (*)(u32))*(u32*)(table + 12))(cursor);
        }
        func_00106420((u32*)base);
        D_0035f5f4 = 0;
    }
    u32 object = D_0035f5f8;
    if (object != 0) {
        u32 table = *(u32*)object;
        ((void (*)(u32))*(u32*)(table + 4))(object);
        D_0035f5f8 = 0;
    }
    D_0035f5fc = 0xff;
    D_0035f5fd = 0xff;
}
