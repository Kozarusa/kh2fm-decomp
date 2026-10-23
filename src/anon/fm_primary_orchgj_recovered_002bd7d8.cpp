#include "../common/types.h"
extern "C" s32 D_003617ec;
extern "C" s32 D_003617f0;
extern "C" s32 D_003617f4;
extern "C" u8 D_003617f8;
extern "C" s32 D_0032b91c;
extern "C" s32 func_00102670(u32, u32);
extern "C" void func_002b8a70(s32);

s32 func_002bd7d8() {
    func_002b8a70(D_003617ec);
    D_003617ec = 0;
    D_003617f0 = 0;
    s32 result = func_00102670(D_0032b91c, D_003617f4);
    D_003617f4 = 0;
    D_003617f8 = 0;
    return result;
}
