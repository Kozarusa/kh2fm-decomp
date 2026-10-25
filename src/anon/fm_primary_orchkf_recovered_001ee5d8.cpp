#include "../common/types.h"
union FloatBits { u32 bits; f32 value; };

f32 func_001ee5d8(u8 twice) {
    // why: random bits come out of qmfc2 in t7 as in accepted fm_primary_queueepsilon_recovered_00203a40.cpp
    register u32 bits asm("$15");
    // why: VU random-state update text identical to accepted fm_primary_queueepsilon_recovered_00203a40.cpp
    asm volatile("addi $8,$0,-1; qmtc2 $8,$vf2; vrxor R,$vf2x; vrnext.x $vf1,R; vrxor R,$vf2x; vrnext.x $vf1,R; vrxor R,$vf2x; vrnext.x $vf1,R; vrxor R,$vf2x; vrnext.x $vf1,R; vrxor R,$vf2x; vrnext.x $vf1,R; vitof0.x $vf2,$vf2; vadd.x $vf1,$vf1,$vf2; qmfc2 %0,$vf1" : "=r"(bits) : : "$8","memory");
    FloatBits first;
    first.bits = bits;
    f32 value = first.value;
    if (twice != 0) {
        // why: second random draw also leaves qmfc2 in t7 as in accepted fm_primary_queueepsilon_recovered_00203a40.cpp
        register u32 more asm("$15");
        // why: VU random-state update text identical to accepted fm_primary_queueepsilon_recovered_00203a40.cpp
        asm volatile("addi $8,$0,-1; qmtc2 $8,$vf2; vrxor R,$vf2x; vrnext.x $vf1,R; vrxor R,$vf2x; vrnext.x $vf1,R; vrxor R,$vf2x; vrnext.x $vf1,R; vrxor R,$vf2x; vrnext.x $vf1,R; vrxor R,$vf2x; vrnext.x $vf1,R; vitof0.x $vf2,$vf2; vadd.x $vf1,$vf1,$vf2; qmfc2 %0,$vf1" : "=r"(more) : : "$8","memory");
        FloatBits second;
        second.bits = more;
        return value + second.value;
    }
    return value + value;
}
