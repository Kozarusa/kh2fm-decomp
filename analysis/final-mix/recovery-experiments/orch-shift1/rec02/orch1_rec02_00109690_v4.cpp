#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u32 func_00133ba0(...);

void func_00109690(u64 value) {
    // why: volatile keeps the original store/load order around the quad store
    volatile u64* object = (volatile u64*)func_00133ba0(value, 2, 0x13000000);
    object[2] = 0;
    *(volatile Quad*)object = 0;
    object[1] = (object[1] & ~0xfULL) | 0xe;
    object[0] = (((object[0] & ~0x7fffULL) | 0x8001ULL) & 0x0fffffffffffffffULL) | 0x1000000000000000ULL;
    object[3] = 0x3f;
}
