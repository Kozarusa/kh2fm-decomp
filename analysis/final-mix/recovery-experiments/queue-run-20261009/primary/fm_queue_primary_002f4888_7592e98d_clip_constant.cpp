#include "../common/types.h"
// Reproduce VU MAC-flag clipping against zero and 4096 in x/y. Preserve the
// original five VU latency slots and return only MAC flag bits 0xc0.
u32 func_002f4888(const f32* position)
{
 asm volatile("vsub.xyzw $vf4,$vf0,$vf0" : : : "memory");
 register u64 upper asm("$2");
 asm("lui %0,0x4580; dsll %0,%0,16; ori %0,%0,0x4580; dsll %0,%0,16" : "=r"(upper));
 register u32 flags asm("$2");
 asm volatile("lqc2 $vf7,0(%1); qmtc2 %2,$vf6; ctc2 $0,$16; "
              "vsub.wxy $vf5,$vf7,$vf4; vsub.xy $vf5,$vf6,$vf7; "
              "vnop; vnop; vnop; vnop; vnop; cfc2 %0,$16"
              : "=r"(flags) : "r"(position),"r"(upper) : "memory");
 return flags&0xc0;
}

