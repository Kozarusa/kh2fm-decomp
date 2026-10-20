#include "../common/types.h"

extern "C" u8* D_0034e948;
extern "C" bool func_0019ba60(u8*);
extern "C" u32 func_0019d358(void*);
extern "C" s32 func_00187300(void*, void*, f32);

s32 func_001874a0(void* target, f32 value) {
    u8* object = D_0034e948;
    s32 result = 0;
    if (func_0019ba60(object)) {
        void* lock = *(void**)(object + 2880);
        if (lock != 0) {
            func_0019d358(lock);
            result = func_00187300(target, *(u8**)(object + 2880) + 4, value);
        }
    }
    return result;
}
