#include "../common/types.h"
extern "C" void func_001a3188(u16,s32,s32);
void func_001d9630(u16* input,s32 n)
{
 if(n>0) {
 register s32 count asm("$16");
 asm volatile("daddu %0,%1,$0" : "=r"(count) : "r"(n));
 u16* p=input;
 do {if(*p){func_001a3188(*p,100,0);*p=0;}--count;++p;}while(count);
 }
}
