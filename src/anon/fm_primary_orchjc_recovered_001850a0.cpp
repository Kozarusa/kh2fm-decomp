#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" u32 func_0016c028(u8*);
extern "C" void func_002cbca0(kn::FVector*, s32, u32, u8*);

kn::FVector* func_001850a0(kn::FVector* out, u8* object) {
    if (*(s32*)(object + 1288) == 0) {
        // why: VU zero-vector store has no C++ equivalent
        asm volatile("vsub.wxyz $vf1,$vf0,$vf0; sqc2 $vf1,0(%0)" : : "r"(out) : "memory");
        return out;
    }
    kn::FVector temp;
    u32 value = func_0016c028(object);
    func_002cbca0(&temp, *(s32*)(object + 1288), value, object + 1360);
    *out = temp;
    return out;
}
