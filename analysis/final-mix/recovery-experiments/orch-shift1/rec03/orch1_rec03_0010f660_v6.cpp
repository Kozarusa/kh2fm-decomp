#include "../common/types.h"
extern "C" u8 D_0036a52c[];
extern "C" u32 func_001064a8(s32);

f32 func_0010f660() {
    f32 value = (f32)func_001064a8(20001);
    return value * *(f32*)D_0036a52c;
}
