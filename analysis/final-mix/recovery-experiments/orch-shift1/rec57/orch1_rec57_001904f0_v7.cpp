#include "../common/types.h"
extern "C" f32 D_0036cd20;
extern "C" s64 func_0016bc20(u64,u64,u32);
extern "C" u32 func_0018a818(void*,u64,s64);
extern "C" u32 func_001902a8(void*,void*,s64);
extern "C" bool func_0019ba60(u64);

void func_001904f0(s32* object, u8* target) {
    func_0019ba60(object[0]);
    s64 result = func_0016bc20(object[0], 19, object[1]);
    if (result != 0) {
        func_0018a818(target, object[0], result);
    } else {
        func_001902a8(object, target, result);
    }
    f32* source = &D_0036cd20;
    *(f32*)(target + 28) = *source;
}
