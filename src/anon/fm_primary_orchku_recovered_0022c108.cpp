#include "../common/types.h"
extern "C" s32 D_0035de64;
extern "C" u32 D_00347f80;
extern "C" u8 D_00347f98[];
extern "C" u8 D_00347e60[];
extern "C" u8 D_0035e340[];
extern "C" u8 D_00347e80[];
extern "C" void func_0031a838(u32);
extern "C" void func_00239700(u32);
extern "C" void func_002361a0(u32);
// why: no recovered source calls func_0022bda0; arguments come from a0, a1 and a2 (masked to a
// byte by its entry andi 0xff), and the result is unused because this caller is void
extern "C" void func_0022bda0(u32, s32, u8);

// why: void per DEVIATIONS #36: the D_0035de64 == 0 exit leaves the untouched entry v0; the
// other exit is the tail into func_0022bda0 (integer v0 from 00239cf0, no live float)

void func_0022c108() {
    s32 state = D_0035de64;
    if (state != 0) {
        s32 mode = 0;
        if (state != 1) {
            mode = 5;
            if (state != 2) {
                mode = 0;
            }
        }
        D_0035de64 = 0;
        u32 allocator = *(u32*)(D_00347f80 + 20);
        u32 table = *(u32*)allocator;
        u32 (*allocate)(u32, u32, u32) = (u32 (*)(u32, u32, u32))(*(u32*)table);
        u32 object = allocate(allocator, 880, 0);
        *(u32*)(object + 0) = (u32)D_00347f98;
        func_0031a838(object + 12);
        *(u32*)(object + 0) = (u32)D_00347e60;
        func_00239700(object + 24);
        *(u32*)(object + 416) = (u32)D_00347f98;
        *(u32*)(object + 0) = (u32)D_0035e340;
        func_0031a838(object + 428);
        *(u32*)(object + 416) = (u32)D_00347e80;
        func_002361a0(object + 448);
        func_0022bda0(object, mode, 0);
    }
}
