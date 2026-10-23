#include "../common/types.h"
extern "C" void func_0016ace0(u8*);

void func_0016adc8(u8* object)
{
 *(u32*)(object+0x108)|=0x200000;
 func_0016ace0(object);
 if(*(u32*)(object+0x588)&2) {
  register u32 vector asm("$16")=(u32)object+0xad0;
  asm volatile("vsub.xyzw $vf1,$vf0,$vf0; sqc2 $vf1,0(%0)" : : "r"(vector) : "memory");
 }
}
