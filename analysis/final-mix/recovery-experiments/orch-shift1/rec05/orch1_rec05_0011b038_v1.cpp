#include "../common/types.h"
extern "C" u32 func_00111e38(s32);
extern "C" u32 func_0011ac10(u64);
extern "C" u32 func_00106a60(s8);
extern "C" u32 func_0016aef0(u64, void*);

void func_0011b038(u64 object) {
    u32 target = func_00111e38(0);
    func_0011ac10(object);
    f32* source = (f32*)func_00106a60(1);
    f32 vec[4];
    vec[0] = source[6];
    vec[2] = source[14];
    vec[3] = 0.0f;
    vec[1] = 0.0f;
    func_0016aef0(target, vec);
}
