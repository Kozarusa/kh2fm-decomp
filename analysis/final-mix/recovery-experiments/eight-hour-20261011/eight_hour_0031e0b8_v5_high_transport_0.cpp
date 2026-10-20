#include "../common/types.h"
extern "C" void func_00106420(u32*);
void func_0031e0b8(u32* object)
{
 register u32 first asm("$14")=0x00350000;
 asm("" : "+r"(first));
 register u32 second asm("$13");
 asm volatile("lui %0,0x35" : "=r"(second));
 first-=29352;
 second-=31080;
 object[0]=first;
 asm("" : : : "memory");
 object[20]=second;
 func_00106420(object);
}
