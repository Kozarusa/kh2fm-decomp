#include "../common/types.h"
extern "C" u32 func_001666f0(void*, u16, u32, u16, u16);

void func_00166808(u8* object, u8 flag, u16 a, u32 b, u16 c, u16 d, s16 e, s16 f) {
    func_001666f0(object, a, b, c, d);
    // why: keeps store order
    *(volatile u8*)(object + 14) = flag;
    *(volatile s16*)(object + 10) = e;
    *(volatile s16*)(object + 12) = f;
    // why: keeps the stores ahead of the epilogue loads
    asm volatile("" ::: "memory");
}
