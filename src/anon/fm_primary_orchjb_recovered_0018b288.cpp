#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" kn::FVector* func_0016c028(u8*);
extern "C" u32 func_0016aef0(u8*, kn::FVector*);
extern "C" bool func_0019ba60(u8*);
extern "C" void func_0017f488(u8*, s32, f32, f32);

void func_0018b288(u8* object, kn::FVector* target, f32 value) {
    if ((*(u32*)(object + 0xb04) & 0x10) == 0) {
        kn::FVector* base = func_0016c028(object);
        kn::FVector delta;
        // why: VU macro vector subtract, pattern from accepted sibling func_00159d30
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                     : : "r"(&delta), "r"(target), "r"(base) : "memory");
        func_0016aef0(object, &delta);
    }
    if (*(*(u8**)(object + 8) + 4) == 15) {
        u8* other = *(u8**)(object + 0xb08);
        if (other != 0 && func_0019ba60(other)) {
            func_0017f488(*(u8**)(object + 0xb08) + 0x140, 50, value, 0.0f);
        }
    }
}
