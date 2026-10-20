#include "../common/types.h"
extern "C" u8* D_0035f3fc;
extern "C" u32 func_001396b0(...);
extern "C" u32 func_0031a260(...);
u32 func_0028cf28(s32 index, s32 value) {
    u8* object = D_0035f3fc + index * 408;
    *(s32*)(object + 396) = value;
    u32 result = func_001396b0(object);
    if (*(s32*)(object + 396) != 0) {
        *(s32*)(object + 400) = 0;
        result = func_001396b0(object);
        if (*(s32*)(object + 400) != 0) return func_0031a260(object, 0);
    }
    return result;
}
