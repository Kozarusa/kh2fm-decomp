#include "../common/types.h"
extern "C" u32 func_001666f0(void*,u16,u32,u16,u16);

void func_00166880(u32 p, u8 a, u16 b, u32 c, u16 d, u16 e, s16 f, s16 g) {
    func_001666f0((void*)p, b, c, d, e);
    *(u8 *)(p + 0xe) = a;
    *(s16 *)(p + 0xa) = f;
    *(s16 *)(p + 0xc) = g;
    asm volatile("" ::: "memory"); // why: keeps stores before epilogue loads
}
