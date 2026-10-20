#include "../common/types.h"
extern "C" f32 D_0036a098[];
extern "C" s32 func_002fea18();
extern "C" s32 func_00313bc0(f32);

void func_001064a8(u32 value) {
    f32 scale = (f32)value;
    f32 random = (f32)func_002fea18();
    f32 divisor = D_0036a098[0];
    func_00313bc0((scale * random) / divisor);
}
