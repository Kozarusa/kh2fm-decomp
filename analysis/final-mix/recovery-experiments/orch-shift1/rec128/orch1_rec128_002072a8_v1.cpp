#include "../common/types.h"
extern "C" f32 func_00207260(void);

s8 func_002072a8(u8 value) {
    u32 count = value;
    func_00207260();
    f32 scaled = (f32)(s32)(count << 1);
    u32 half = count >> 1;
    f32 random = func_00207260();
    return (s8)(s32)(scaled * random - (f32)(s32)half);
}