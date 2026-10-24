#include "../common/types.h"
extern "C" f32 D_0036c578;
extern "C" f32 D_0036c57c;
extern "C" u8* D_00352130;
extern "C" u8* func_00177860(u8*);
extern "C" void func_0017f488(u8*, s32, f32, f32);
extern "C" void func_0017f5e0(u8*, s32, void*, f32, f32);

s32 func_0017e138(u8* object, s32 value) {
    *(u32*)(object + 0x7f8) &= ~4;
    u8* motion = object + 0x140;
    if (*(s32*)(motion + 0x14) == 0x36) {
        register f32* speed asm("$14") = &D_0036c578; // why: original builds this address in t6
        asm("" : "+r"(speed)); // why: keeps the global address in a register before the lwc1
        func_0017f488(motion, 0x37, *speed, 0.0f);
        func_0017f5e0(motion, 0, 0, 0.0f, 0.0f);
    }
    u8* ability = func_00177860(object);
    u32 flags = *(u32*)(ability + 0x10);
    register f32* pointer asm("$14") = &D_0036c57c; // why: original builds this address in t6
    asm("" : "+r"(pointer)); // why: keeps the global address in a register before the lwc1
    f32 scale = *pointer;
    if ((flags & 8) == 0) {
        scale = *(f32*)(D_00352130 + 0x54);
    }
    return (s32)((f32)value * scale);
}
