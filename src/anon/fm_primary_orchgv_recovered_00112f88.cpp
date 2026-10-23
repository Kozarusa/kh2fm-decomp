#include "../common/types.h"
#include "../kn/fvector.hpp"
typedef unsigned int Quad __attribute__((mode(TI)));

struct Local {
    u8 head[12];
    s32 zero;
    Quad value;
};

extern "C" u32 func_00190140(s32*);
extern "C" kn::FVector* func_00190388(kn::FVector*, s32*);
extern "C" s32 func_0016bba8(...);
extern "C" u32 func_0018a818(void*, u8*, s32);

s32 func_00112f88(s32* target) {
    s32 best = 0;
    u32 valid = 0;
    if (func_00190140(target)) {
        valid = *target != 0;
    }
    if ((valid & 0xff) != 0) {
        register u8* object asm("$18") = *(u8**)target; // why: original keeps the object in s2
        if ((*(u32*)(object + 1416) & 2) != 0) {
            Local local;
            kn::FVector position;
            kn::FVector temporary;
            kn::FVector* point = &position;
            local.zero = 0;
            func_00190388(point, target);
            f32 nearest = 0.0f;
            s32 entry = 0;
            Quad* value = &local.value;
            kn::FVector* scratch = &temporary;
            while ((entry = func_0016bba8(object, 2, entry)) != 0) {
                func_0018a818(&local, object, entry);
                register f32 distance asm("$f0"); // why: original moves the squared distance into f0
                // why: VU macro squared distance, same sequence as the accepted 00163210/0018a4d8 siblings
                asm volatile("lqc2 $vf1,0(%2); lqc2 $vf2,0(%3); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%1); lqc2 $vf1,0(%1); vmul.xyz $vf1,$vf1,$vf1; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; qmfc2 $8,$vf1; mtc1 $8,%0"
                             : "=f"(distance) : "r"(scratch), "r"(point), "r"(value) : "$8", "memory");
                if (best == 0 || distance < nearest) {
                    nearest = distance;
                    best = entry;
                }
            }
        }
    }
    return best;
}
