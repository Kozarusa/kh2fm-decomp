#include "../common/types.h"
extern "C" u8 D_00350ce0;
extern "C" f32 D_0036d858;
extern "C" void func_00185b00(u32*,u64,u64);
void func_001ae9a0(u32* object,u64 second,u64 third)
{
 func_00185b00(object,second,third);
 *object=(u32)&D_00350ce0;
 object[0x162]|=0x400;
 register u8* nested asm("$13")=(u8*)object+1648;
 asm("" : "+r"(nested));
 register f32* scale asm("$15")=&D_0036d858;
 asm("" : "+r"(scale));
 *(u32*)(nested+264)=0;
 *(f32*)(nested+260)=*scale;
 object[0x2af]|=0x8404;
}
