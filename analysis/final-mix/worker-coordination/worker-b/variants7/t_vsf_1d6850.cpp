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

void func_001d6850(u32 phase, u32 priority) {
    register u32 mask asm("$12") = 0xffffu;
    register u32 one asm("$11") = 1u;
    asm("" : "+r"(mask), "+r"(one));
    if (priority == mask && phase == one) {
        register f32* source asm("$13") = &D_0036e5ec;
        asm("" : "+r"(source));
        D_01d5ba78.value = *source; D_01d5ba78.second = 0; D_01d5ba78.first = 0;
    }
    if (priority == mask && phase == one) {
        register f32* source asm("$15") = &D_0036e5f0;
        asm("" : "+r"(source));
        D_01d5ba88.first = 3; D_01d5ba88.second = 0; D_01d5ba88.value = *source;
    }
}
