#include "../common/types.h"
extern "C" s32 D_00350f1c;
extern "C" s32 D_0032b91c;
extern "C" u8 D_001b1ee8[];
extern "C" s32* D_01d48c44;
extern "C" s32* func_00102818(s32, s32, s32, u8*, s32);

void func_001b1e80(s32 value) {
    if (value != -1 && value != D_00350f1c) {
        D_01d48c44 = func_00102818(D_0032b91c, 0, 350000, D_001b1ee8, 4096);
        D_01d48c44[1] = value;
    }
}
