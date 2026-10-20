typedef unsigned int u32;
extern u32 D_01dae688[6], D_0035ebf8, D_0035ebfc;
void func_00241f20(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register u32* page asm("$12") = D_01dae688;
        register u32* full asm("$13") = D_01dae688;
        asm("" : "+r"(page), "+r"(full));
        u32 first = D_0035ebf8;
        full[4] = 0;
        asm volatile("" ::: "memory");
        full[1] = 0x3c4;
        asm volatile("" ::: "memory");
        page[0] = first;
        asm volatile("" ::: "memory");
        u32 second = D_0035ebfc;
        full[2] = second;
        asm volatile("" ::: "memory");
        full[3] = 0x8a58;
        full[5] = 0x00010000u | 0xfc0u;
    }
}
