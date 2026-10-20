#include "../common/types.h"

extern "C" void func_001fab48(void*);

void func_001fb928(u8* object, u32* source, u8* other) {
    u8* base = object + **(s32* volatile*)(other + 12) + 160;
    func_001fab48(object);
    if (source[0] == *(u32*)(object + 12)) {
        *(f32*)(base + 32) = *(f32*)((u8*)source + 12);
        asm volatile("" ::: "memory"); // why: keeps load/store order
        *(f32*)(base + 40) = (f32)*(u16*)((u8*)source + 16);
        asm volatile("" ::: "memory"); // why: keeps load/store order
        *(f32*)(base + 44) = (f32)*(u16*)((u8*)source + 18);
    }
}