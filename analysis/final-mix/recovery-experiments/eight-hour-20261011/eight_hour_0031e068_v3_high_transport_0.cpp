#include "../common/types.h"
extern "C" void func_00106420(u32*);
void func_0031e068(u32* object)
{
 register u32 second asm("$13")=0x00350000;
 asm("" : "+r"(second));
 register u32 first asm("$15");
 asm volatile("lui %0,0x35" : "=r"(first));
 second-=31080;
 first-=29352;
 object[0]=first;
 asm("" : : : "memory");
 object[36]=second;
 object[104]=second;
 func_00106420(object);
}
