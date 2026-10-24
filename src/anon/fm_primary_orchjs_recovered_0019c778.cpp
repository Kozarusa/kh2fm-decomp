#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_0036d3a8;
extern "C" u64 func_001b9d40(...);
extern "C" u64 func_0016af58(...);

u32 func_0019c778(u8* object, kn::FVector* direction) {
    u32 result = 0;
    if (func_001b9d40(object) != 0 && 0.0f < *(f32*)(object + 0x1c)) {
        kn::FVector temp;
        f32 dot;
        func_0016af58(&temp, object);
        // why: VU macro xyz dot product, same sequence as accepted 00162b18
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vmul.xyz $vf1,$vf1,$vf2; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; qmfc2 $8,$vf1; mtc1 $8,%0"
                     : "=f"(dot) : "r"(direction), "r"(&temp) : "$8", "memory");
        register const f32* limit asm("$15") = &D_0036d3a8; // why: original forms the limit address in t7
        asm volatile("" : "+r"(limit)); // why: original forms the full address before the lwc1
        f32 threshold = *limit;
        if (threshold <= dot) {
            // why: VU macro xyz dot product, same sequence as accepted 00162b18
            asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vmul.xyz $vf1,$vf1,$vf2; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; qmfc2 $8,$vf1; mtc1 $8,%0"
                         : "=f"(dot) : "r"(direction), "r"(object + 16) : "$8", "memory");
            if (threshold <= dot) {
                result = 1;
            }
        }
    }
    return result;
}
