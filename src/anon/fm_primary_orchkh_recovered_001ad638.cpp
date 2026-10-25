#include "../common/types.h"
extern "C" u8 D_00350a70[];
extern "C" u8 D_00350a56;
extern "C" u8 D_00350ab0[];
extern "C" u8 D_00350bb0[];
extern "C" void func_001c11a8(s32);
extern "C" u32 func_0014c9f0(u32);
extern "C" s32 func_00239870(u8*);
extern "C" void func_0031e668(u8*);
extern "C" void func_001ac5b8(u32*);

typedef void (*Method)(u8*);

void func_001ad638(u8* object) {
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
    asm volatile("" ::: "memory"); // why: original calls with jal and returns itself instead of a tail jump (pattern of accepted func_00145ab8)
}
