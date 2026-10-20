typedef unsigned int u32;
typedef float f32;
extern f32 D_0036dfd4, D_0036dfd8, D_01d498c0, D_01d498c4;
extern u32 D_01d498d0;
extern "C" void func_0031b9e0(void*);
void func_001c7ab8(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        D_01d498c0 = D_0036dfd4;
    }
    asm volatile("" ::: "memory");
    if (priority == 0xffffu && phase == 1) {
        D_01d498c4 = D_0036dfd8;
    }
    if (priority == 0xffffu && phase == 1) {
        func_0031b9e0(&D_01d498d0);
    }
}
