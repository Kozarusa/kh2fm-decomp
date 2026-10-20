#include "../common/types.h"
extern "C" f32 func_00207260(void);

s8 func_002072a8(u8 value) {
    func_00207260();
    f32 scaled = (f32)(value << 1);
    return (s8)(s32)(scaled * func_00207260() - (f32)(value >> 1));
}
