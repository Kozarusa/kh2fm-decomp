#include "../common/types.h"
typedef u32* (*AllocateFunc)(void*, s32, s32);
struct Allocator {
    AllocateFunc* vtable;
};
extern "C" u8* D_00347f80;
extern "C" char D_0035e028;
extern "C" char D_00347f98;
extern "C" char D_00347e60;
extern "C" void func_0031a838(u32);
extern "C" void func_00239700(u32);
// why: no recovered source calls 00228788; its every exit ends in store-only callees (001396b0, 0031a260) that write no v0, so it is declared void
extern "C" void func_00228788(u32*);

void func_002289f0(void) {
    Allocator* allocator = *(Allocator**)(D_00347f80 + 20);
    u32* object = (*allocator->vtable)(allocator, 1248, 0);
    s32 count = 2;
    u32* cursor;
    object[3] = 0;
    object[0] = (u32)&D_0035e028;
    cursor = object + 6;
    do {
        cursor[0] = (u32)&D_00347f98;
        count--;
        func_0031a838((u32)(cursor + 3));
        cursor[0] = (u32)&D_00347e60;
        func_00239700((u32)(cursor + 6));
        cursor += 102;
    } while (count != -1);
    func_00228788(object);
}
