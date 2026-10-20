#include "../common/types.h"
// Keep explicit vector addresses; folded store offsets alter the original range.

void func_00178cf8(u8* object)
{
 register u32 first asm("$14")=(u32)object+32;
 asm volatile("vsub.xyzw $vf1,$vf0,$vf0; sqc2 $vf1,0(%0)" : : "r"(first) : "memory");
 register u32 child asm("$15")=*(u32*)(object+0xb44);
 child+=0xa30;
 asm volatile("vsub.xyzw $vf1,$vf0,$vf0; sqc2 $vf1,0(%0)" : : "r"(child) : "memory");
 register u32 last asm("$4")=(u32)object+16;
 asm volatile("vsub.xyzw $vf1,$vf0,$vf0; sqc2 $vf1,0(%0); nop" : : "r"(last) : "memory");
}
