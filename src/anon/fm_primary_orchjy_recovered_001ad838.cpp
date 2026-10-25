#include "../common/types.h"
extern "C" u8 D_00350a70[];
extern "C" u8 D_00350a56;
extern "C" u8 D_00350ab0[];
extern "C" u8 D_00350bb0[];
// why: copied from fm_primary_orchbk_recovered_00191938.cpp
extern "C" void func_001c11a8(s32);
// why: copied from fm_primary_oneword_recovered_001c8710.cpp
extern "C" u32 func_0014c9f0(u32);
// why: copied from fm_primary_orchfv_recovered_0031b648.cpp
extern "C" s32 func_00239870(u8*);
// why: no accepted caller in the packet; one a0 argument from the original registers
extern "C" void func_0031e668(u8*);
// why: copied from fm_primary_queuealphaprime_recovered_0031f4b8.cpp
extern "C" void func_001ac5b8(u32*);
// why: copied from fm_primary_oneword_recovered_001bf0c8.cpp; only a pointer is passed, no float promotion; 00105110 returns its final vtable call result in v0
extern "C" u32 func_00105110(...);

typedef void (*Method)(u8*);

u32 func_001ad838(u8* object) {
    *(u32*)object = (u32)D_00350a70;
    D_00350a56 = 0;
    func_001c11a8(12);
    func_0014c9f0(8);
    *(u32*)object = (u32)D_00350ab0;
    if ((u32)object + 3280 != 0) {
        u8* cursor = object + 4656;
        u8* begin = object + 3280;
        for (;;) {
            if (begin == cursor) break;
            cursor -= 344;
            (**(Method**)cursor)(cursor);
        }
    }
    func_00239870(object + 2936);
    *(u32*)object = (u32)D_00350bb0;
    if ((u32)object + 1544 != 0) {
        u8* cursor = object + 2920;
        u8* begin = object + 1544;
        for (;;) {
            if (begin == cursor) break;
            cursor -= 344;
            (**(Method**)cursor)(cursor);
        }
    }
    func_00239870(object + 1200);
    func_00239870(object + 848);
    func_00239870(object + 484);
    func_0031e668(object + 132);
    func_001ac5b8((u32*)object);
    return func_00105110(object);
}
