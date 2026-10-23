#include "../common/types.h"
extern "C" f32 D_00370bc8;
union ConvertedWord { f32 storage; s32 word; };
// Preserve VU R state and FPU current-rounding conversion; a C++ cast would truncate.

s32 func_00222568(void)
{
 register f32 storage asm("$f1");
 asm volatile("addi $8,$0,-1; qmtc2 $8,$vf2; vrxor R,$vf2x; vitof0.x $vf2,$vf2; vrnext.x $vf1,R; vadd.x $vf1,$vf1,$vf2; qmfc2 $15,$vf1; mtc1 $15,$f0; lui $15,%%hi(D_00370bc8); addiu $15,$15,%%lo(D_00370bc8); lwc1 $f1,0($15); mul.s $f0,$f0,$f1; cvt.w.s %0,$f0"
              : "=f"(storage) : : "$8","$15","$f0","memory");
 ConvertedWord result; result.storage=storage; return result.word;
}
