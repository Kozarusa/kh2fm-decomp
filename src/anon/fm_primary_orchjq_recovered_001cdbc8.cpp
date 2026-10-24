#include "../common/types.h"
#include "../kn/fvector.hpp"
struct Area;
struct Entry {
    u8 head;
    u8 kind;
    u8 body[66];
};
struct EntryList {
    s32 count;
    Entry entries[0];
};
extern "C" f32 D_0036e2b8;
extern "C" s32 func_001a0920(u8*, u8*);
extern "C" s32 func_001a0800(f32 x, f32 y, f32 z, Area* area, void* actor, f32* offset);

void func_001cdbc8(u8* object, f32* target, u32 id) {
    kn::FVector direction;
    kn::FVector temp;
    // why: VU macro vector subtract, same sequence as accepted 001b7df0
    asm volatile("lqc2 $vf1,0(%0); lqc2 $vf2,0(%1); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%2)"
                 : : "r"(target + 4), "r"(object + 80), "r"(&temp) : "memory");
    direction = temp;
    f32 height = *(f32*)&direction.y;
    *(f32*)&direction.y = 0.0f;
    f32 length;
    // why: VU macro normalize xyz in place returning the length, same sequence as accepted 0016d760
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                 : "=f"(length) : "r"(&direction) : "$8", "memory");
    f32 distance = length - target[1];
    f32 zero = 0.0f;
    if (distance < zero) {
        distance = zero;
    }
    f32 dot;
    // why: VU macro xyz dot product, same sequence as accepted 00162b18
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vmul.xyz $vf1,$vf1,$vf2; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; qmfc2 $8,$vf1; mtc1 $8,%0"
                 : "=f"(dot) : "r"(&direction), "r"(object + 48) : "$8", "memory");
    register const f32* limit asm("$14") = &D_0036e2b8; // why: original forms the limit address in t6
    asm("" : "+r"(limit)); // why: original forms the full address before the lwc1
    f32 cosine = *limit;
    if (dot < cosine) {
        // why: VU macro xyz dot product, same sequence as accepted 00162b18
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vmul.xyz $vf1,$vf1,$vf2; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; qmfc2 $8,$vf1; mtc1 $8,%0"
                     : "=f"(cosine) : "r"(&direction), "r"(object + 48) : "$8", "memory");
    }
    for (u32 index = 0; (s32)index < ((EntryList*)*(u32*)(object + 68))->count; index++) {
        if (((EntryList*)*(u32*)(object + 68))->entries[index].kind == id) {
            if (func_001a0920((u8*)&((EntryList*)*(u32*)(object + 68))->entries[index], *(u8**)(object + 64))) {
                s32 inside = func_001a0800(distance, height, cosine, (Area*)&((EntryList*)*(u32*)(object + 68))->entries[index], *(void**)(object + 64), target);
                u32* flags = (u32*)(object + 96);
                u32 mask = 1u << (index & 31);
                u32* bits = flags + (index >> 5);
                if (inside) {
                    *bits |= mask;
                }
            }
        }
    }
}
