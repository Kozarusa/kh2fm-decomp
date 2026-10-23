#include "../common/types.h"
extern "C" u8 D_004574d0[];
extern "C" void func_002f2aa0(u8*, s32, u32, s32, s32, s32, s32, s32);
extern "C" void func_003058a0(u32);
extern "C" void func_002f25a0(u32, u32);
extern "C" s32 func_002f2d60(u8*, u32);

s32 func_0014dec0(u16* image, u32 source) {
    s16 width = image[2];
    s16 height = image[3];
    func_002f2aa0(D_004574d0, (s16)(image[0] << 5), (u16)width >> 6, 1, 0, 0, width, height);
    func_003058a0(0);
    func_002f25a0(0, 0);
    return func_002f2d60(D_004574d0, source);
}
