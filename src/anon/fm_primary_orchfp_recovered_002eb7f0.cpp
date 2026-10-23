#include "../common/types.h"
extern "C" u32 func_0017f5e0(s32, s32, s32, f32, f32);
extern "C" u32 func_0017f5f8(s32, s32, s32, f32, f32);
extern "C" s32 func_002eaf40(s32);

u32 func_002eb7f0(s32 object, s32 index, f32 value) {
    func_0017f5f8(object + 0x140, index, 0, value, 0.0f);
    s32 target = func_002eaf40(object);
    return func_0017f5e0(target + 0x140, index - 101, 0, value, 0.0f);
}
