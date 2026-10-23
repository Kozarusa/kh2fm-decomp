#include "../common/types.h"
extern "C" void func_00195858(void*,s32);
// Reset the object's mode, clear its vector, and copy its configured scalar.

void func_002ece98(u32 unused,u8* object)
{
 func_00195858((void*)(u32)((u32)object+0x110),62);
 register u32 vector asm("$15")=(u32)object+32;
 asm volatile("vsub.xyzw $vf1,$vf0,$vf0; sqc2 $vf1,0(%0)" : : "r"(vector) : "memory");
 *(f32*)(object+0xf0)=*(f32*)(object+0x128);
}
