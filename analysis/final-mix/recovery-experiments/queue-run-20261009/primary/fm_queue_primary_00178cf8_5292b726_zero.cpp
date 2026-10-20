#include "../common/types.h"
struct __attribute__((aligned(16))) VUVector { f32 x,y,z,w; };
// Reset two embedded vectors and one vector in the pointed-to child object.
void func_00178cf8(u8* object)
{
 register VUVector* first asm("$14")=(VUVector*)(u32)((u32)object+32);
 asm volatile("vsub.xyzw $vf1,$vf0,$vf0; sqc2 $vf1,%0" : "=m"(*first) : : "memory");
 register u32 child asm("$15")=*(u32*)(object+0xb44);
 child+=0xa30;
 asm volatile("vsub.xyzw $vf1,$vf0,$vf0; sqc2 $vf1,0(%0)" : : "r"(child) : "memory");
 register VUVector* last asm("$4")=(VUVector*)(u32)((u32)object+16);
 asm volatile("vsub.xyzw $vf1,$vf0,$vf0; sqc2 $vf1,%0; nop" : "=m"(*last) : : "memory");
}
