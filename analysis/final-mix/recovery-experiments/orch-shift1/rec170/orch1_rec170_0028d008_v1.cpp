#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u8* D_0035f3fc;
extern "C" s32 D_0035f410;
u32 func_0028d008(u32 index) {
    u32 result;
    if (D_0035f3fc != 0) {
        result = func_00139d78(D_0035f3fc + index * 408);
    } else {
        result = 0;
    }
    if (result != 0 && ((D_0035f410 >> (index & 31)) & 1) != 0) {
        result = 0;
    }
    return result;
}
