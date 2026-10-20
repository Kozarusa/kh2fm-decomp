#include "../common/types.h"
extern "C" u32 func_00133ba0(...);

void func_00109690(u64 value) {
    u64* object = (u64*)func_00133ba0(value, 2, 0x13000000);
    object[2] = 0;
    *(u32*)object = 0;
    *(u32*)((u8*)object + 4) = 0;
    *(u32*)(object + 1) = 0;
    *(u32*)((u8*)object + 0xc) = 0;
    object[1] = (object[1] & ~0xfULL) | 0xe;
    object[0] = (((object[0] & ~0x7fffULL) | 0x8001ULL) & 0x0fffffffffffffffULL) | 0x1000000000000000ULL;
    object[3] = 0x3f;
}
