typedef unsigned int u32;
typedef float f32;
extern f32 D_0036e5ec, D_0036e5f0;
struct S { u32 a; u32 b; f32 c; } D_01d5ba78, D_01d5ba88;
void func_001d6850(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register f32* src asm("$15") = &D_0036e5ec;
        asm("" : "+r"(src));
        *((f32*)0x01d5ba78 + 2) = *src;
        ((u32*)0x01d5ba78)[1] = 0;
        ((u32*)0x01d5ba78)[0] = 0;
    }
    if (priority == 0xffffu && phase == 1) {
        register f32* src2 asm("$15") = &D_0036e5f0;
        asm("" : "+r"(src2));
        ((u32*)0x01d5ba88)[0] = 3;
        ((u32*)0x01d5ba88)[1] = 0;
        *((f32*)0x01d5ba88 + 2) = *src2;
    }
}
