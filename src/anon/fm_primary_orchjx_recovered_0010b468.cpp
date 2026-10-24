#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_0036a438;

// Preserve original registry aliases.
u8 func_0010b468(u8* history, kn::FVector* point) asm("_Z16wtarget_0010b468jjjj");

u8 func_0010b468(u8* history, kn::FVector* point) {
    history[1] = 0;
    s32 index = *(s32*)(history + 4);
    if (index < 0) {
        kn::FVector* slot = (kn::FVector*)(history + 0x10);
        for (s32 count = 31; count >= 0; count--) {
            *slot = *point;
            slot++;
        }
        *(s32*)(history + 4) = 0;
    } else {
        kn::FVector difference;
        // why: VU macro vector subtract, same sequence as accepted sibling fm_primary_orchjj_recovered_0018d840.cpp
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                     : : "r"(&difference), "r"(point), "r"(history + index * 16 + 0x10) : "memory");
        register f32 dot asm("$f1"); // why: original moves the dot product into $f1
        // why: VU macro xyz dot product, same sequence as accepted sibling fm_primary_queueeta_recovered_00162b18.cpp
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vmul.xyz $vf1,$vf1,$vf2; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; qmfc2 $8,$vf1; mtc1 $8,%0"
                     : "=f"(dot) : "r"(&difference), "r"(&difference) : "$8", "memory");
        f32* limit = &D_0036a438;
        asm("" : "+r"(limit)); // why: original forms the full address before the load
        if (!(*limit <= dot)) {
            goto done;
        }
        s32 next = *(s32*)(history + 4) + 1;
        next = next % 32;
        *(s32*)(history + 4) = next;
        *(kn::FVector*)(history + next * 16 + 0x10) = *point;
        history[0] = 1;
    }
    history[1] = 1;
done:
    return history[1];
}
