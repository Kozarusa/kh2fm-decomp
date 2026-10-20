#include "../common/types.h"
extern "C" u8 D_00350778[];
extern "C" void func_0018d050(u32*, s32, s32, s32, s32, s32, s32);
extern "C" void func_001a4530(u32*);

void func_001a4498(u32* object, s32 a, s32 b, s32 c, s32 d, s32 e) {
    func_0018d050(object, a, a, b, d, e, c);
    *(volatile u32*)&object[0x32] = 0;
    *(volatile u32*)&object[0x31] = 0;
    f32 value = *(volatile f32*)&object[0x32];
    // why: keeps address arithmetic after the 200 read
    asm volatile("" ::: "memory");
    *(volatile u32*)&object[0] = (u32)D_00350778;
    *(volatile u32*)&object[0x33] = 0;
    volatile f32* vector = (volatile f32*)(object + 0x40);
    vector[0] = value;
    vector[3] = value;
    vector[1] = value;
    vector[2] = value;
    func_001a4530(object + 0x44);
    object[1] = object[1] | 0x100;
}
