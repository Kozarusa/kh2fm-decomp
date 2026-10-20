#include "../common/types.h"
extern "C" u32 func_0028da70(u64,s32);
extern "C" s8 D_0035f24c;
extern "C" s32 D_0035f244;
extern "C" u8 D_00374050[];
u32 func_0027ead0() {
    s32 object = D_0035f244;
    u8* pointer = D_00374050+D_0035f24c*6;
    return func_0028da70(object,*(s16*)(pointer+4));
}


