#include "../common/types.h"
extern "C" s32 D_00352c40;
extern "C" s32 D_01d9e6c4;
extern "C" s32 D_01da8cd0[];
extern "C" u8 D_01d9e5b0[];
extern "C" u8 D_0036eef0[];
extern "C" u64 func_00313b80(f32);
extern "C" u32 func_002fee78(...);

u8* func_001e6188() {
    s32* info = D_01da8cd0;
    u8* buffer = D_01d9e5b0;

         u64 ratio = func_00313b80((f32)D_01d9e6c4 / (f32)D_00352c40 * 100.0f);
    func_002fee78(buffer, D_0036eef0, info[4], info[0], info[5], info[1], info[6], info[2], ratio);
    return buffer;
}
