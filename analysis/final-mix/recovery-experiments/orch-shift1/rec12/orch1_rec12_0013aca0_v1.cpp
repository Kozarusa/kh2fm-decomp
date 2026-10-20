#include "../common/types.h"
extern "C" s32 D_00348058;
extern "C" void func_0013aa78(s32, s32, s32, s32, s32, s32, s32);

s32 func_0013aca0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 base = D_00348058;
    s32 index = *(s32*)(base + 0x6ed0) - 1;
    *(s32*)(base + 0x6ed0) = index;
    s32 result = base + *(s32*)(index * 4 + base + 0x6e40) * 0x310;
    func_0013aa78(result, a, b, c + 0x20, d, e, f);
    return result;
}
