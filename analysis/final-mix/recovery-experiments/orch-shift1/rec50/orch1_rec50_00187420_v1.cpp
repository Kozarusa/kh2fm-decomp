#include "../common/types.h"
extern "C" s32 D_0034e948;
extern "C" bool func_0019ba60(u64);
extern "C" u32 func_0019d358(void*);
extern "C" s32 func_001871c8(void*, void*, f32);

s32 func_00187420(void* object, f32 scale) {
    s32 target = D_0034e948;
    s32 result = 0;
    if (func_0019ba60(target)) {
        s32 inner = *(s32*)(target + 0xb40);
        if (inner != 0) {
            func_0019d358((void*)inner);
            result = func_001871c8(object, (void*)(*(s32*)(target + 0xb40) + 4), scale);
        }
    }
    return result;
}