#include "../common/types.h"
#include "../kn/fvector.hpp"
struct Motion {
    kn::FVector position;
    kn::FVector weight;
    f32 first;
    f32 pad0; // why: unused gap, keeps second at +0x28
    f32 second;
    f32 pad1; // why: unused gap, keeps result at +0x30 where the callee writes it
    kn::FVector result;
    u8 pad2[48]; // why: fields not touched here, keep flags at +0x70
    // why: bitfield write reproduces the ld/and/sd of bit 0 the original shows
    union {
        u64 raw;
        struct {
            u64 enabled : 1;
            u64 mode : 2;
            u64 rest : 61; // why: remaining bits, bit 34 is read through raw
        } bits;
    } flags;
    u8 pad3[24]; // why: struct is 0x90 bytes (frame puts s0 at sp+160), copied by func_00319e90
};
extern "C" u8 D_003a9250[];
extern "C" u8* D_00341708;
extern "C" f32 D_0036a53c;
extern "C" f32 D_0036a540;
extern "C" u64 func_00146730(...);
extern "C" kn::FVector* func_0016c028(u8*);
extern "C" f32 func_002f8870(f32);
extern "C" void func_00319e90(Motion*, u8*);
extern "C" u64 func_00143928(...);

s32 func_00110b00(u8* entity, kn::FVector* goal, u32 other) {
    register u8* object asm("$17") = entity; // why: original keeps the object in s1
    register kn::FVector* target asm("$18") = goal; // why: original keeps the target vector in s2
    kn::FVector difference;
    Motion motion;
    u64 clip = func_00146730(D_003a9250, other);
    if (clip == 1) {
        return 0;
    }
    if (clip != 0) {
        return 0;
    }
    u8* player = D_00341708;
    if ((*(u32*)(player + 0x160) & 0x4000) != 0) {
        return 0;
    }
    kn::FVector* base = func_0016c028(player);
    // why: VU macro vector subtract, pattern from accepted sibling func_00159d30
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(&difference), "r"(target), "r"(base) : "memory");
    f32 scale = *(f32*)(object + 0xb80);
    if (0.0f < *(f32*)&difference.y * scale) {
        return 0;
    }
    *(f32*)&difference.y = 0.0f;
    f32 absolute = func_002f8870(scale);
    f32* near = &D_0036a53c;
    asm("" : "+r"(near)); // why: original forms the full address before the load (pattern from accepted func_0019bfd0)
    if (absolute < *near) {
        f32 dot;
        // why: VU macro xyz dot product, sequence from accepted sibling func_00162b18
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vmul.xyz $vf1,$vf1,$vf2; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; qmfc2 $8,$vf1; mtc1 $8,%0"
                     : "=f"(dot) : "r"(object + 0xba0), "r"(&difference) : "$8");
        if (0.0f < dot) {
            return 0;
        }
    } else {
        f32 dot;
        // why: VU macro xyz dot product, sequence from accepted sibling func_00162b18
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vmul.xyz $vf1,$vf1,$vf2; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; qmfc2 $8,$vf1; mtc1 $8,%0"
                     : "=f"(dot) : "r"(object + 0xba0), "r"(&difference) : "$8");
        f32* far = &D_0036a540;
        asm("" : "+r"(far)); // why: original forms the full address before the load (pattern from accepted func_0019bfd0)
        if (*far < dot) {
            return 0;
        }
    }
    Motion* current = &motion;
    asm("" : "+r"(current), "+r"(object)); // why: original forms the motion address before object+0x590, so the two keep separate s registers
    func_00319e90(current, object + 0x590);
    current->position = *target;
    // why: VU macro zero-fill of a 16-byte vector, copied from accepted sibling func_00178570
    asm volatile(
        "vsub.xyzw $vf1,$vf0,$vf0;"
        "sqc2 $vf1,0(%0)" : : "r"(&motion.weight) : "memory");
    motion.flags.bits.enabled = 0;
    func_00143928(current);
    u64 mask = (u64)1 << 34; // why: a named mask keeps the and+sltiu test the original shows (a literal folds to a shift)
    return (motion.flags.raw & mask) == 0;
}
