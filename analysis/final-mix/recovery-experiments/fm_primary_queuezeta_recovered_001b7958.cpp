#include "../common/types.h"

void func_001b7958(u8* object,const f32* translation)
{
 register s32 index asm("$13")=0;
 register s32 count asm("$15")=*(s32*)object;
 if(count<=0) return;
 register u32 entry asm("$14")=(u32)object+32;
 do {
  asm volatile("lqc2 $vf1,0(%0); lqc2 $vf2,0(%1); vadd.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
               : : "r"(entry),"r"(translation) : "memory");
  count=*(s32*)object;
  ++index;
  entry+=32;
 } while(index<count);
}
