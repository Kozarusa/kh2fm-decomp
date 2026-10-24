#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" bool func_00180cd0(...);
extern "C" f32 func_002f8ad0(f32,f32);
typedef s32 (*MatrixGetter)(u8*, f32*, f32);

kn::FVector* func_0017fe10(kn::FVector* out, u8* motion, f32 time) {
    f32 zero = 0.0f;
    f32 frame = time;
    f32 matrix[16];
    if (time < zero) {
        frame = *(f32*)(motion + 0x30);
    }
    if (!func_00180cd0(motion)) {
        s32 moving = zero < *(f32*)(motion + 0x34);
        asm("" : "+r"(moving)); // why: original materialises the compare flag and masks it with andi 0xff before the test
        if (!(u8)moving) {
            u8* object = *(u8**)(motion + 0xc);
            if (((MatrixGetter*)*(u8**)object)[6](object, matrix, frame) == 0) {
                goto store;
            }
        }
    }
    // why: VU macro zero-vector store, same sequence as accepted sibling fm_primary_orchfj_recovered_002c17d8.cpp
    asm volatile("vsub.wxyz $vf1,$vf0,$vf0; sqc2 $vf1,0(%0)" : : "r"(out) : "memory");
    return out;
store:
    f32* result = (f32*)out;
    result[1] = -matrix[13];
    result[0] = matrix[12];
    result[2] = -matrix[14];
    result[3] = -func_002f8ad0(matrix[8], matrix[10]);
    return out;
}
