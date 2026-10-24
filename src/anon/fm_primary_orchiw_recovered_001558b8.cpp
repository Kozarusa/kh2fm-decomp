#include "../common/types.h"
extern "C" u32 func_00139598(u8* object);
extern "C" u32 func_001395a8(u8* object);
extern "C" u8 func_00139d78(u8* object);
extern "C" s32 func_00155758(s32 value, s32* x, s32* y, s32* width, s32* height, f32* angle);
extern "C" void func_0013edd0(u8* object, f32 rotation);
extern "C" void func_0014b1e0(u8* rect, s16 x, s16 y);
extern "C" void func_0014b208(u8* rect, u16 width, u16 height);
extern "C" u32 func_00138d30(u8* sprite, f32 rotation);

s32 func_001558b8(u8* object, s32 value, s32 index) {
    s32 x;
    s32 y;
    s32 width;
    s32 height;
    f32 angle;
    u8* entry = object + index * 592;
    u8* sprite = entry + 13232;
    u8* rect = entry + 13552;
    func_00139598(sprite);
    s32 result = func_00155758(value, &x, &y, &width, &height, &angle);
    if (result == 0) {
        f32 rotation = angle;
        func_00139d78(sprite);
        func_0013edd0(entry + 13264, rotation);
        s32 left = x;
        s32 top = y;
        s32 w = width;
        s32 h = height;
        func_00139d78(sprite);
        func_0014b1e0(rect, (s16)left, (s16)top);
        func_0014b208(rect, (u16)w, (u16)h);
        result = func_001395a8(sprite);
        if (index == 1) {
            result = func_00138d30(object + 9588, -angle);
        }
    }
    return result;
}
