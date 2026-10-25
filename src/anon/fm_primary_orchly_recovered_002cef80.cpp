#include "../common/types.h"
#include "../kn/fvector.hpp"
struct __attribute__((aligned(16))) Vector4 { f32 x; f32 y; f32 z; f32 w; };
struct Box { s32 words[8]; };
extern "C" u8* D_00361f60;
extern "C" void func_001444c8(Box*, Vector4*, Vector4*);
extern "C" void func_0011b6a8(void*);
extern "C" void func_001449a8(Box*, kn::FVector*);
extern "C" s32 func_002cec08(u8*, Box*);

bool func_002cef80(s32 unused, kn::FVector* position) {
    Vector4 minimum;
    Vector4 maximum;
    Box box;
    kn::FVector matrix[4];
    kn::FVector* translation = &matrix[3];
    f32 zero = 0.0f;
    minimum.x = -100.0f;
    minimum.y = -100.0f;
    minimum.z = -100.0f;
    minimum.w = zero;
    maximum.x = 100.0f;
    maximum.y = 100.0f;
    maximum.z = 100.0f;
    maximum.w = zero;
    func_001444c8(&box, &minimum, &maximum);
    func_0011b6a8(matrix);
    *translation = *position;
    *(f32*)&translation->w = 1.0f;
    func_001449a8(&box, matrix);
    return func_002cec08(D_00361f60, &box) != 0;
}
