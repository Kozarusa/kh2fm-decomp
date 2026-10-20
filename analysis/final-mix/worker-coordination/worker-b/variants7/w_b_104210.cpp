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
void func_00104210(s32 value) {
    register s32 positive asm("$15") = 0 < value;
    asm("" : "+r"(positive));
    register s32 current asm("$14") = value;
    register s32 one asm("$12") = 1;
    asm("" : "+r"(one));
    if (!positive) current = one;
    register u32 selected asm("$4") = 2;
    asm("" : "+r"(selected));
    D_0032ba84 = current;
    if (current == 2) { func_00104200(selected); return; }
    if (current >= 3) {
        if (current == 3) { selected = 3; func_00104200(selected); }
        return;
    }
    if (current != 1) { func_00104200(selected); return; }
    selected = 1;
}
