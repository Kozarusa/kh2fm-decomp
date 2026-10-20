#include "../common/types.h"
struct Vec4 {
    f32 x;
    f32 y;
    f32 z;
    s32 w;
};
extern "C" Vec4 D_00350990;
extern "C" void func_001024a8(u32);

void func_001733f8(s32 object) {
    if ((*(s32*)(object + 4))-- <= 0) {
        D_00350990.z = *(f32*)(object + 16);
        D_00350990.x = *(f32*)(object + 8);
        D_00350990.y = *(f32*)(object + 12);
        D_00350990.w = 0;
        func_001024a8(object);
    }
}