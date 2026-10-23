#include "../common/types.h"
struct Blob {
    u8 data[88];
} __attribute__((aligned(4)));
struct Color {
    u8 red;
    u8 green;
    u8 blue;
    u8 pad;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};
extern "C" Blob D_004f36a8;
extern "C" Blob D_004f3650;
extern "C" Blob D_004f3700;
extern "C" u8 D_0036b3f0[];
extern "C" u8 D_004f3744;
extern "C" void func_0015c4b8();
extern "C" s32 func_0015cc80(Color*);
extern "C" void func_0010a8a8(f32, f32);
extern "C" void func_0010a828(f32, f32);
extern "C" void func_0010a7d8(u8, u8, u8);
extern "C" void func_001dd1e8(u8, u8);
extern "C" void func_001dd1b0(f32, f32);
extern "C" u32 func_001dd1c8(u8, u8, u8);

u32 func_0015c6d0(Blob* source) {
    D_004f36a8 = *source;
    D_004f3650 = D_004f36a8;
    D_004f3700 = *source;
    func_0015c4b8();
    u8* base = D_004f3700.data;
    if (*(f32*)(base + 84) == 0.0f) {
        register f32* pointer asm("$14") = (f32*)D_0036b3f0; // why: original forms the address in t6
        asm("" : "+r"(pointer));  // why: keeps the address materialized before the load
        *(f32*)(base + 84) = *pointer;
    }
    Color* color = (Color*)(base + 68);
    u8* red = &D_004f3744;
    if (func_0015cc80(color) == 0) {
        func_0010a8a8(color->z, color->w);
        func_0010a828(color->x, color->y);
        func_0010a7d8(*red, color->green, color->blue);
    }
    func_001dd1e8((u8)(s32)color->z, (u8)(s32)color->w);
    func_001dd1b0(color->x, color->y);
    return func_001dd1c8(*red, color->green, color->blue);
}
