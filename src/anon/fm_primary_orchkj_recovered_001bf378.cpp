#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_0036dca8;
extern "C" f32 D_0036dcac;
extern "C" f32 D_0036dcb0;
// why: no accepted caller; the callee passes a0 to YS::OBJ::get_entry_id and returns (id == 0x883)
extern "C" bool func_001bfca0(u8*);
extern "C" s32 func_001991a8(s32, s32);            // copied from accepted caller fm_primary_orchjn_recovered_00197a00.cpp
extern "C" u16 func_0016a070(s32);                 // copied from accepted caller fm_primary_fiveword_recovered_0016fa58.cpp
extern "C" s32 func_001a3018(u32, u32, s32);       // copied from accepted caller fm_primary_orchjo_recovered_001a3188.cpp
extern "C" u32 func_001a3188(u64,u64,u8);          // copied from accepted caller fm_primary_clearsequence_recovered_001d7940.cpp
extern "C" s32 func_0016c028(s32);                 // copied from accepted caller fm_primary_orchjp_recovered_001a4ff8.cpp
// why: no accepted caller; the callee writes a 16-byte vector through the hidden result pointer in a0 and returns it
extern "C" kn::FVector func_0016be98(s32);
extern "C" u32 func_0016bd60(u64,u64);             // copied from accepted caller fm_primary_fiveword_recovered_001b2780.cpp

// Return contract (DEVIATIONS #36): the only exit follows the final call func_0016bd60, whose tail call goes
// into func_0016bd10 (accepted definition void): v0 is stale-b; the clamp result in $f0 crossed that call
// (stale-a). The accepted declaration (fm_primary_orchcl_recovered_001bfc28.cpp) is void(u8*, s32).

void func_001bf378(u8* object, s32 target) {
    *(s32*)(object + 0x9e8) = target;
    if (func_001bfca0(object) != 0) {
        u8* other = *(u8**)(object + 0x9e8);
        if ((*(u32*)(other + 0x588) & 0x80) != 0) {
            func_001991a8(81, 1);
            other = *(u8**)(object + 0x9e8);
        }
        *(s32*)(other + 0xacc) += 1;
    } else {
        s32 entry = func_001a3018(*(u32*)(object + 0x9b4), func_0016a070(*(s32*)(object + 0x9e8)), 1);
        if (entry != 0) {
            func_001a3188(*(s32*)(object + 0x9b4), entry, 0);
        }
    }
    *(u32*)(object + 0x9e0) |= 4;
    kn::FVector* direction = (kn::FVector*)(object + 0x9d0);
    // why: original keeps the base vector pointer in s0 and &position in s1
    register kn::FVector* base asm("$16") = (kn::FVector*)func_0016c028((s32)object);
    kn::FVector temporary;
    kn::FVector position = func_0016be98(*(s32*)(object + 0x9e8));
    // why: VU macro vector subtract, text identical to accepted func_001a4ff8 (fm_primary_orchjp_recovered_001a4ff8.cpp); trailing directives emit nothing and keep gas from moving sqc2 into the delay slot
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0); .set noreorder; .set reorder"
                 : : "r"(&temporary), "r"(base), "r"(&position) : "memory");
    *direction = temporary;
    register f32 length asm("$f1"); // why: original receives the VU length in f1
    // why: VU macro xyz length, text identical to accepted func_001a4ff8 (fm_primary_orchjp_recovered_001a4ff8.cpp)
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf1,$vf1,$vf1; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; vsqrt Q,$vf1x; vwaitq; cfc2 $8,$22; mtc1 $8,%0"
                 : "=f"(length) : "r"(direction) : "$8", "memory");
    register f32* scale asm("$15") = &D_0036dca8; // why: original forms each constant address in t7, one after the other
    asm("" : "+r"(scale)); // why: original forms the full address before the load
    f32 value = length * *scale;
    register f32* low asm("$15") = &D_0036dcac; // why: original reuses t7 for this address after the multiply
    asm("" : "+r"(low)); // why: original forms the full address before the load
    f32 clamped;
    if (value < *low) {
        clamped = *low;
    } else {
        f32* high = &D_0036dcb0;
        asm("" : "+r"(high)); // why: original forms the full address before the load
        if (*high < value) {
            clamped = *high;
        } else {
            clamped = value;
        }
    }
    *(f32*)(object + 0x9c0) = clamped;
    *(f32*)(object + 0x9bc) = clamped;
    func_0016bd60((s32)object, 13);
}
