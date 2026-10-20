typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;
typedef float f32;
struct FmInitFloat { u32 first, second; f32 value; };
extern FmInitFloat D_01d5ba78, D_01d5ba88;
extern u32 D_01dae688[6], D_0035ebf8, D_0035ebfc;
extern u8 D_01d498d0;
extern f32 D_0036dfd4, D_0036dfd8, D_01d498c0, D_01d498c4;
extern f32 D_0036e5ec, D_0036e5f0;
extern "C" void func_0031b9e0(void*);
extern "C" void func_00104200(u32);
extern u32 D_0032ba84;
void func_00241f20(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register u32* base asm("$12") = D_01dae688;
        asm("" : "+r"(base));
        u32 first = D_0035ebf8;
        base[4] = 0;
        asm volatile("" ::: "memory");
        base[1] = 0x3c4;
        base[0] = first;
        asm volatile("" ::: "memory");
        base[2] = D_0035ebfc;
        base[3] = 0x8a58;
        base[5] = 0x00010000u | 0xfc0u;
    }
}
