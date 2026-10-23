#include "../common/types.h"
extern "C" u32 func_001667d0(u32 a0);

u64 func_00166730(u8* object) {
    u32 result = func_001667d0(*(u16*)(object + 4));
    u64 low = (u64)(u32)(*(s32*)object << 5) | 0x2000000000000000ULL;
    u64 mode = (u64)result << 26 | 0x400000000ULL;
    u64 height = (u64)*(u16*)(object + 8) << 20 | 0x240000000ULL;
    u64 width = (u64)(u16)(*(u16*)(object + 4) >> 6) << 14 | 0x8000000000000ULL;
    return low | width | height | mode;
}
