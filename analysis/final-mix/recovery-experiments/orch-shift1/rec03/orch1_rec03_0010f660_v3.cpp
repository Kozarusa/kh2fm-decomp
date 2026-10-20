#include "../common/types.h"
extern "C" f32 D_0036a52c;
extern "C" u32 func_001064a8(s32);

f32 func_0010f660() {
    f32 value = (f32)func_001064a8(20001);
    f32* scale = &D_0036a52c;
    return value * *scale;
}
