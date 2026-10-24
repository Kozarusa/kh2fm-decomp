#include "../common/types.h"
extern "C" s32 func_00196e88(f32, u32, s32, s32);

s32 func_001973f0(u32 object) {
    // why: the original reads the full halfword (lhu); a plain read is narrowed to lbu
    if ((u8)(*(volatile u16*)(*(u32*)(object + 0x3c) + 2) & 1) != 0) {
        return func_00196e88(0.0f, object, 6, 2);
    }
    return func_00196e88(0.0f, object, 6, 0);
}
