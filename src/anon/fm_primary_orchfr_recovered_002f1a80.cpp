#include "../common/types.h"
extern "C" s32 D_00363c2c;
extern "C" s32 D_00363c28;
extern "C" u8 D_01e2c100[];
extern "C" u8 D_002f1a68[];
extern "C" u32 func_00168388(s32, u8*, u8*, s32);

u32 func_002f1a80() {
    D_00363c2c = 0;
    return func_00168388(D_00363c28, D_01e2c100, D_002f1a68, 0);
}
