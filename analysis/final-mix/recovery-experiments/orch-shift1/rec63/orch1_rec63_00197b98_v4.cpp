#include "../common/types.h"

extern "C" u8* D_0035037c;
extern "C" u8 D_0036d0a8[];
extern "C" s32 func_002283f8();

f32 func_00197b98() {
    f32 result = 0.0f;
    u8* object = D_0035037c;
    if (object != 0) {
        s32 type = *(s32*)(object + 0x30);
        result = *(volatile f32*)D_0036d0a8;
        if (type == 8) {
            result = (f32)func_002283f8();
        }
    }
    return result;
}
