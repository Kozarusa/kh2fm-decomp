#include "../common/types.h"
extern "C" u8 D_0032dfd0[];

u32 func_001d9d48(u8* data) {
    return (*(u32*)((u32)(data[1] >> 5) * 4 + (u32)data[0] * 8 + (u32)D_0032dfd0) & (1 << (data[1] & 0x1f))) != 0;
}
