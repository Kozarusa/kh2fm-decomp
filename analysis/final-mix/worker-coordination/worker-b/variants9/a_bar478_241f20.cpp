typedef unsigned int u32;
extern u32 D_01dae688[6], D_0035ebf8, D_0035ebfc;
void func_00241f20(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        u32* base = D_01dae688;
        u32 first = D_0035ebf8;
        base[4] = 0;
        base[1] = 0x3c4;
        asm volatile("" ::: "memory");
        base[0] = first;
        u32 second = D_0035ebfc;
        base[2] = second;
        asm volatile("" ::: "memory");
        base[3] = 0x8a58;
        asm volatile("" ::: "memory");
        base[5] = 0x00010000u | 0xfc0u;
    }
}
