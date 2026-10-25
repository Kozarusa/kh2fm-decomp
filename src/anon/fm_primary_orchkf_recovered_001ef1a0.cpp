#include "../common/types.h"
union FloatBits { u32 bits; f32 value; };

f32 func_001ef1a0(u8 flag) {
    register u32 bits asm("$15"); // why: original moves the VU random result through t7, as in accepted fm_primary_queueepsilon_recovered_00209fb8.cpp
    // why: VU random-state update, VU text identical to accepted fm_primary_queueepsilon_recovered_00209fb8.cpp
    asm volatile("addi $8,$0,-1; qmtc2 $8,$vf2; vrxor R,$vf2x; vrnext.x $vf1,R; vrxor R,$vf2x; vrnext.x $vf1,R; vrxor R,$vf2x; vrnext.x $vf1,R; vrxor R,$vf2x; vrnext.x $vf1,R; vrxor R,$vf2x; vrnext.x $vf1,R; vitof0.x $vf2,$vf2; vadd.x $vf1,$vf1,$vf2; qmfc2 %0,$vf1" : "=r"(bits) : : "$8","memory");
    FloatBits first;
    first.bits = bits;
    f32 value = first.value;
    if (flag != 0) {
        register u32 more asm("$15"); // why: original moves the second VU random result through t7, as in accepted fm_primary_queueepsilon_recovered_00209fb8.cpp
        // why: VU random-state update, VU text identical to accepted fm_primary_queueepsilon_recovered_00209fb8.cpp
        asm volatile("addi $8,$0,-1; qmtc2 $8,$vf2; vrxor R,$vf2x; vrnext.x $vf1,R; vrxor R,$vf2x; vrnext.x $vf1,R; vrxor R,$vf2x; vrnext.x $vf1,R; vrxor R,$vf2x; vrnext.x $vf1,R; vrxor R,$vf2x; vrnext.x $vf1,R; vitof0.x $vf2,$vf2; vadd.x $vf1,$vf1,$vf2; qmfc2 %0,$vf1" : "=r"(more) : : "$8","memory");
        FloatBits second;
        second.bits = more;
        return value + second.value;
    }
    return value + value;
}
