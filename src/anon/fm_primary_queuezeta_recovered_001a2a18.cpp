#include "../common/types.h"
extern "C" void func_0016bd60(u8*,s32);

void func_001a2a18(u8* object)
{
 register u32 vector asm("$14")=(u32)object+32;
 asm volatile("vsub.xyzw $vf1,$vf0,$vf0; sqc2 $vf1,0(%0)" : : "r"(vector) : "$31","memory");
 register u32 flags asm("$13")=*(u32*)(object+0x160);
 register s32 mode asm("$5")=0;
 if(!(flags&0x40)) { mode=5; asm("" : "+r"(mode)); }
 func_0016bd60(object,mode);
}
