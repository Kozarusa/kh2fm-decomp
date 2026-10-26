#include "../common/types.h"
extern "C" u64 func_00111e38(s32);
extern "C" u32 func_0011ac10(u64);
extern "C" u32 func_00106a60(s8);
extern "C" u32 func_0016aef0(u64, void*);

void func_0011b038(u64 object) {
    u64 target = func_00111e38(0);
    func_0011ac10(object);
    f32* source = (f32*)func_00106a60(1);
    f32 vec[4];
    f32 x = source[6];
    f32 z = source[14];
    // why: a zero held in a local shared by both stores; two 0.0f literals compile 4 bytes shorter (measured)
    f32 zero = 0.0f;
    vec[0] = x;
    vec[2] = z;
    vec[1] = zero;
    vec[3] = zero;
    func_0016aef0(target, vec);
}
