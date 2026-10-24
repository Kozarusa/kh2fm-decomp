#include "../common/types.h"
extern "C" s32 func_00139598(u8* object);
extern "C" s32 func_001395a8(u8* object);
extern "C" s32 func_00155830(s32 value, f32* x, f32* y, f32* z);
extern "C" s32 func_00239f18(u8* object, f32 value);
extern "C" s32 func_00138d30(u8* sprite, f32 rotation);
extern "C" s32 func_00138c68(u8* sprite, s32 x, s32 y);

s32 func_001559e8(u8* object, s32 value, s32 index) {
    f32 x;
    f32 y;
    f32 z;
    u8* entry = object + index * 412;
    u8* sprite = entry + 6704;
    func_00139598(sprite);
    s32 result = func_00155830(value, &x, &y, &z);
    if (result == 0) {
        func_00239f18(entry + 6728, x);
        result = func_001395a8(sprite);
        if (index == 4) {
            u8* target = object + 9588;
            func_00138d30(target, z);
            result = func_00138c68(target, (s32)-y, 0);
        }
    }
    return result;
}
