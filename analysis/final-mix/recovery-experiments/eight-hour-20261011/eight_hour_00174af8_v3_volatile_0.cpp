#include "../common/types.h"
extern "C" void func_001b1bb8(f32,u32,u32,u32,u32,u32);
void func_00174af8(const u32* object)
{
 register const u32* saved asm("$15")=object;
 register u32 first asm("$4")=saved[0];
 asm("" : "+r"(saved) : "r"(first));
 f32 scalar=*(const f32*)(saved+4);
 u32 second=*((const volatile u32*)saved+1);
 u32 third=*((const volatile u32*)saved+2);
 u32 fourth=*((const volatile u32*)saved+3);
 func_001b1bb8(scalar,first,second,third,fourth,0x80);
}
