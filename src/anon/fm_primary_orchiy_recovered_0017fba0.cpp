#include "../common/types.h"
extern "C" void func_0011c138(void*);
extern "C" u32 func_0011c4b0(u32);
extern "C" u32 func_0011c4e8(u32, u32, u32, u32, void*, u32, f32);
extern "C" u32 func_0011c6a8(u32, u32, u32, u32, u32, void*, u32, f32);
extern "C" u32 func_001808c0(u8*, void*);
extern "C" u32 func_00180a10(u8*, void*);
extern "C" bool func_00180cd0(u8*);
extern "C" u32 func_001b0580(u8*);

struct Element {
    u8 data[32];
    Element() { func_0011c138(this); }
    ~Element() {}
    static bool isPositive(f32 number) { return 0.0f < number; }
};

void func_0017fba0(u8* entry, u32 value) {
    register u8* object asm("$19") = entry; // why: original keeps the object in s3
    u32 target = *(u32*)(*(u8**)(object + 8) + 0x670);
    register u32 flags asm("$12") = *(u32*)(object + 0x104); // why: original loads these flags into t4
    register u32 state asm("$13") = *(u32*)(object + 0x20); // why: original loads this word into t5
    *(u32*)(object + 0x104) = (flags | 1) & ~2;
    *(u32*)(object + 0x20) = state & ~0x80;
    if (target == 0) {
        return;
    }
    if (!func_00180cd0(object)) {
        Element elements[16];
        func_001808c0(object, elements);
        u32 result = func_001b0580(*(u8**)(object + 8) + 0x4a0);
        f32 divisor = *(f32*)(object + 0x34);
        bool positive = Element::isPositive(divisor);
        if (positive) {
            func_0011c6a8(target, value, *(u32*)(object + 0xd0), *(u32*)(object + 0xd4), result, elements, 0,
                          *(f32*)(object + 0x30) / divisor);
        } else {
            func_0011c4e8(target, value, *(u32*)(object + 0xc), result, elements, 0, *(f32*)(object + 0x30));
        }
        func_00180a10(object, elements);
        *(u32*)(object + 0x104) |= 2;
    } else {
        func_0011c4b0(target);
    }
}
