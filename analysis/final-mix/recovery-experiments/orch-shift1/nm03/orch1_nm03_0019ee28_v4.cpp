#include "../common/types.h"
extern "C" s32 D_00350448;
extern "C" f32 D_00350464;

void func_0019ee28(s32 flag, s64 id) {
    if (id == 0xffff && flag == 1) {
        f32 zero = 0.0f;
        u8* base = (u8*)&D_00350448;
        // why: materializes the base address in its own register before the +32 store
        asm("" : "+r"(base));
        *(f32*)(base + 32) = zero;
        // why: keeps store order
        asm volatile("" ::: "memory");
        D_00350448 = 0;
        D_00350464 = zero;
    }
}
