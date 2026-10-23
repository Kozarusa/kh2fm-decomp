#include "../common/types.h"
extern "C" s32 func_001541d8(u8*, s32*, s32);
extern "C" s32 func_00154288(u8*, s32);
extern "C" s32 func_001386e0(u8*, s32, s32, u8*, s32, s32);
extern "C" s32 func_001391c8(u8*, s32, s32);
extern "C" s32 func_00138748(u8*);

s32 func_00153fa0(u8* object, s32 value, s32 mode, s32 key, s32 face, s32 extra) {
    s32 result;
    *(s32*)(object + 832) = mode;
    result = 0;
    if (func_001541d8(object, &result, key) == 1) {
        return func_001386e0(object, value, result, object + 416, func_00154288(object, face), extra);
    }
    func_001391c8(object, value, extra);
    return func_00138748(object);
}
