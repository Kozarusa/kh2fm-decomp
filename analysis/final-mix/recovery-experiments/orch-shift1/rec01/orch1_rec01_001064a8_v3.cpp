#include "../common/types.h"
extern "C" f32 D_0036a098;
extern "C" s32 func_002fea18();
extern "C" f32 func_00313bc0(f32);

void func_001064a8(u32 value) {
    f32 scale = (f32)value;
    f32 random = (f32)func_002fea18();
    func_00313bc0((scale * random) / D_0036a098);
}

