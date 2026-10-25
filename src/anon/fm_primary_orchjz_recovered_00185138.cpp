#include "../common/types.h"
#include "../kn/fvector.hpp"
struct Motion {
    kn::FVector position;
    kn::FVector weight;
    f32 first;
    f32 pad0; // why: unused gap, keeps second at +0x28 as the original stores it
    f32 second;
    f32 pad1; // why: unused gap, keeps result at +0x30 where the callee writes it
    kn::FVector result;
    u8 pad2[48]; // why: fields not touched here, keep flags at +0x70
    // why: bitfield writes keep the separate mode store and the unfolded bit-0 update the original shows
    union {
        u64 raw;
        struct {
            u64 enabled : 1;
            u64 mode : 2;
            u64 rest : 61; // why: remaining bits, bit 32 is read through raw
        } bits;
    } flags;
    u8 pad3[24]; // why: struct is 0x90 bytes (frame puts s0 at sp+144), copied by func_00319e90
};
extern "C" f32 D_0036c8c8;
extern "C" void func_00319e90(Motion*, u8*);
extern "C" kn::FVector* func_0016c028(u8*);
extern "C" u64 func_00143928(...);

s32 func_00185138(u8* object, kn::FVector* out, u8 flag, f32 limit) {
    Motion motion;
    func_00319e90(&motion, object + 0x590);
    motion.position = *func_0016c028(object);
    // why: VU macro store of vf0 (0,0,0,1), sqc2 pattern from accepted sibling func_0019bfd0
    asm volatile("sqc2 $vf0,0(%0)" : : "r"(&motion.weight) : "memory");
    motion.flags.bits.mode = 2;
    if (flag != 0) {
        motion.flags.bits.enabled = 1;
    } else {
        motion.flags.bits.enabled = 0;
    }
    f32 time = 0.0f;
    s32 result = 0;
    if (time < limit) {
        f32* stepAddress = &D_0036c8c8;
        asm("" : "+r"(stepAddress)); // why: original forms the full address before the load (pattern from accepted func_0019bfd0)
        f32 step = *stepAddress;
        u64 mask = (u64)1 << 32;
        do {
            time = time + step;
            if (limit < time) {
                time = limit;
            }
            motion.second = time;
            motion.first = time;
            func_00143928(&motion);
            if (flag == 0 && (motion.flags.raw & mask) != 0) {
                return result;
            }
            motion.position = motion.result;
            *out = motion.result;
            result = 1;
        } while (time < limit);
    }
    return result;
}
