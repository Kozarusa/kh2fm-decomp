#include "../common/types.h"
extern "C" u32 func_00281b30();
extern "C" u8 D_0035f298;
extern "C" f32 D_003741a4;
extern "C" f32 D_0035f294;
extern "C" u16 D_0035f280;
u32 func_00281cf0(s32 value) {
    D_0035f298 = 0;
    D_0035f294 = D_003741a4;
    u32 result = func_00281b30();
    D_0035f280 = value;
    return result;
}
