#include "../common/types.h"
extern "C" f32 func_00314698(u32, u32, u32, u32);
extern "C" u32 func_003147a0(void*, void*);

f32 func_003144b0(u64 value) {
    u32 output[8];
    func_003147a0(&value, output);
    u64 count = *(u64*)((u8*)output + 16);
    s32 shifted = (s32)((s64)(count << 2) >> 32);
    // why: original builds shifted result in t5 for movn
    register s32 setBit asm("$13") = shifted | 1;
    if ((count & 0x3fffffff) != 0) {
        shifted = setBit;
    }
    return func_00314698(output[0], output[1], output[2], (u32)shifted);
}
