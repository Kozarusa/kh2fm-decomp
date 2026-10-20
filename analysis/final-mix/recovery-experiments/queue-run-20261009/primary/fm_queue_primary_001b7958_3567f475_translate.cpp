#include "../common/types.h"
// Translate each 32-byte entry's leading vector; reload count each iteration,
// as the supplied translation vector may alias the container.
void func_001b7958(u8* object,const f32* translation)
{
 register s32 index asm("$13")=0;
 register u32 entry asm("$14")=(u32)object+32;
 while(index<*(s32*)object) {
  asm volatile("lqc2 $vf1,0(%0); lqc2 $vf2,0(%1); vadd.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
               : : "r"(entry),"r"(translation) : "memory");
  ++index;
  entry+=32;
 }
}
