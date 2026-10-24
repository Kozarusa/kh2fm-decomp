#include "../common/types.h"
#include "../kn/fvector.hpp"
typedef unsigned int Quad __attribute__((mode(TI)));

struct Local {
    u8 head[12];
    s32 zero;
    Quad value;
};

extern "C" u32 func_00190128(void*);
extern "C" u8* func_00185da8(u8*);
extern "C" u32 func_0019bc38(u32);
extern "C" u64 func_0019bb58(...);
extern "C" s32 func_0016bba8(...);
extern "C" u32 func_0018a818(void*, u8*, s32);
extern "C" s32 func_0016c028(s32);
extern "C" u32 func_00190140(s32*);

u8* func_00191218(f32 offset, s32* target, s32 source) {
    Local local;
    kn::FVector vector;
    kn::FVector temporary;
    u8* object = 0;
    local.zero = 0;
    f32 best = 0.0f;
    func_00190128(target);
    while ((object = func_00185da8(object)) != 0) {
        if (func_0019bc38((u32)object) == 0) {
            continue;
        }
        if (func_0019bb58(object) == 0) {
            continue;
        }
        s32 entry = 0;
        while ((entry = func_0016bba8(object, 3, entry)) != 0) {
            if ((*(u16*)(entry + 2) & 1) != 0) {
                continue;
            }
            func_0018a818(&local, object, entry);
            kn::FVector* point = &vector;
            kn::FVector* origin = (kn::FVector*)func_0016c028(source);
            // why: VU macro vector subtract, pattern from accepted sibling func_0018df90; trailing directives emit nothing and keep gas from moving sqc2 into the delay slot, as in 001605a0
            asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0); .set noreorder; .set reorder"
                         : : "r"(&temporary), "r"(&local.value), "r"(origin) : "memory");
            *point = temporary;
            f32 length;
            // why: VU macro vector length, pattern from accepted sibling func_00116d08
            asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf1,$vf1,$vf1; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; vsqrt Q,$vf1x; vwaitq; cfc2 $8,$22; mtc1 $8,%0"
                         : "=f"(length) : "r"(point) : "$8", "memory");
            f32 distance = length;
            if ((*(u32*)(object + 1416) & 0x400) != 0) {
                distance = length - offset;
            }
            if (func_00190140(target) == 0 || distance < best) {
                *target = (s32)object;
                best = distance;
                target[1] = *(u8*)entry;
            }
        }
    }
    return object;
}
