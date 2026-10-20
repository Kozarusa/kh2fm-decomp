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
void func_001c7ab8(u32 phase, u32 priority) {
    register void* saved asm("$30") = 0;
    asm volatile("" : "+r"(saved));
    if (priority == 0xffffu && phase == 1) {
        register f32* source asm("$15") = &D_0036dfd4;
        asm("" : "+r"(source));
        D_01d498c0 = *source;
    }
    if (priority == 0xffffu && phase == 1) {
        register f32* source asm("$15") = &D_0036dfd8;
        asm("" : "+r"(source));
        D_01d498c4 = *source;
    }
    if (priority == 0xffffu && phase == 1) func_0031b9e0(&D_01d498d0);
    asm volatile("" ::: "memory");
}
