#include "../common/types.h"
extern "C" s32 D_01d5b9e0;
extern "C" s32 D_01d5b9e4;
extern "C" s32 D_01d5b9e8;
extern "C" s32 D_01d5b9f0;
extern "C" s32 D_01d5b9f4;
extern "C" f32 D_01d5b9f8;
extern "C" f32 D_0036e2ec;

void func_001ce668(u32 mode, u32 id) {
    if (id == 0xffff && mode == 1) {
        D_01d5b9e0 = 0;
        D_01d5b9e8 = 0;
        D_01d5b9e4 = 0;
    }
    if (id == 0xffff && mode == 1) {
        D_01d5b9f0 = 0;
        D_01d5b9f4 = 0;
        D_01d5b9f8 = D_0036e2ec;
    }
}