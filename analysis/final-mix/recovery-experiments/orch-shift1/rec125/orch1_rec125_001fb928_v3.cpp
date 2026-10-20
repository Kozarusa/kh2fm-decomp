#include "../common/types.h"

extern "C" void func_001fab48(void*);

void func_001fb928(u8* object, volatile u8* source, u8* other) {
    u8* base = object + **(s32**)(other + 12) + 160;
    func_001fab48(object);
    if (*(volatile u32*)source == *(u32*)(object + 12)) {
        *(f32*)(base + 32) = *(volatile f32*)(source + 12);
        *(f32*)(base + 40) = (f32)*(volatile u16*)(source + 16);
        *(f32*)(base + 44) = (f32)*(volatile u16*)(source + 18);
    }
}