#include "../common/types.h"
extern "C" s32 D_00361f60;
extern "C" s32 func_002cf280(u32*, u32, u32);
extern "C" u8* func_002dc7c8(s32);

u8* func_002de698(u8* object) {
    s32 target = D_00361f60;
    func_002cf280((u32*)(object + 2800), 8, 0);
    u8* result = func_002dc7c8(target);
    *(f32*)(object + 3060) = *(f32*)(result + 172);
    return result;
}
