#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" kn::FVector D_00363550;
extern "C" f32 D_01e2c060;
extern "C" void func_002eb6f8(f32, u32, s32);
extern "C" s32 func_0016c028(s32);

s32 func_002eca38(s32 owner, u32 object) {
    f32 zero = 0.0f;
    func_002eb6f8(zero, object, 269);
    D_01e2c060 = zero;
    s32 result = func_0016c028((s32)object);
    // why: a plain Quad copy folds the address into sq (rec217 v1-v4, 10 words); the original uses the kn::FVector assignment (self check, lq/sq through t0)
    D_00363550 = *(kn::FVector*)result;
    return result;
}
