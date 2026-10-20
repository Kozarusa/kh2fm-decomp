#include "../common/types.h"
extern "C" u64 func_001e3650(u32);
extern "C" u64 func_001e3660(u64, s32);
extern "C" u64 func_001e38f8(u64, u8*, s32, s32);
extern "C" u64 func_001e3a88(u64, u8*, s32, s32);

void func_001e3c18(u8* object) {
    u32 handle = *(u32*)(object + 136);
    s16 second = *(s16*)(object + 158);
    s16 first = *(s16*)(object + 156);
    u64 value = func_001e3650(handle);
    value = func_001e3660(value, 2);
    value = func_001e38f8(value, *(u8**)(object + 140) + 192, first, second);
    func_001e3a88(value, *(u8**)(object + 140) + 208, first, second);
    asm volatile("" ::: "memory"); // why: keeps the last call from becoming a tail call
}