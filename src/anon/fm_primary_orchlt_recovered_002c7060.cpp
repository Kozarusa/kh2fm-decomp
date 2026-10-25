#include "../common/types.h"
#include "../kn/fvector.hpp"

struct Blend {
    u8 pad00[0x30];
    kn::FVector start;
    kn::FVector end;
    f32 elapsed;
    f32 duration;
};

extern "C" f32 D_00349e10;
extern "C" void func_0017d748(kn::FVector* result, Blend* blend, f32 ratio);
// why: the accepted C++ alias declaration of func_0016ace0 fails the isolated link with an unresolved set_pos reference; extern "C" resolves in the full build via alias generation
extern "C" u32 func_0016ace0(u8* object, const kn::FVector& vector);

u32 func_002c7060(Blend* blend, u8* target) {
    kn::FVector position;
    blend->elapsed = blend->elapsed + D_00349e10;
    if (blend->elapsed < blend->duration) {
        func_0017d748(&position, blend, blend->elapsed / blend->duration);
        return func_0016ace0(target, position);
    }
    u32 result = func_0016ace0(target, blend->start);
    // why: original subtracts the two vectors with VU macro instructions; kn::FVector has no operator-; same lqc2/lqc2/vsub/sqc2 shape as accepted 0018df90 and 0018b288, which spell the mask .xyzw while this function needs .wxyz (the original)
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.wxyz $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)" : : "r"(&position), "r"(&blend->end), "r"(&blend->start) : "memory");
    blend->duration = 0;
    return result;
}
