typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;
extern f32 D_0036e5ec, D_0036e5f0;
struct S { u32 a; u32 b; f32 c; } D_01d5ba78, D_01d5ba88;
void func_001d6850(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register u32 keep asm("$14") = (u32)&D_0036e5f0;
        asm("" : "+r"(keep));
        register f32* src asm("$12") = &D_0036e5ec;
        asm("" : "+r"(src));
        u32* p = (u32*)&D_01d5ba78;
        p[0] = 0;
        p[1] = 0;
        ((f32*)p)[2] = *src;
    }
    if (priority == 0xffffu && phase == 1) {
        register f32* src asm("$15") = &D_0036e5f0;
        asm("" : "+r"(src));
        u32* p = (u32*)&D_01d5ba88;
        p[0] = 3;
        p[1] = 0;
        ((f32*)p)[2] = *src;
    }
}
