#include "../common/types.h"
extern "C" u8 D_0032bae0;
extern "C" u32 func_002362b0(...);
extern "C" u32 func_002367c8(...);
extern "C" u32 func_00105c30(void);
extern "C" s32 func_00241ed8(s32);
extern "C" u32 func_001386e0(u8*, s32, s32, u8*, s32, s32);

u32 func_0015aba8(u8* object, s32 unused, s32 value) {
    u8* base = object + 416;
    s32 flag = 0;
    s32 result = 0;
    func_002362b0(base);
    func_002367c8(base);
    if (func_00105c30() == 1 || func_00105c30() == 8) {
        flag = 1;
    }
    if ((u8)flag == 0) {
        result = func_00241ed8(D_0032bae0) != 0;
    }
    return func_001386e0(object, 20000, value, base, result, 0);
}
