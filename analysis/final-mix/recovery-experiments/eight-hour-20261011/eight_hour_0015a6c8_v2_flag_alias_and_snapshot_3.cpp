#include "../common/types.h"
extern "C" u8 D_0034aa40;
void func_0015a6c8(u32* input)
{
 register u32 first asm("$13")=input[0];
 register u32 high asm("$14")=0x350000;
 asm("" : "+r"(first),"+r"(high));
 register u32* output asm("$12")=(u32*)(high-21904);
 asm("" : "+r"(output));
 *(u32*)(high-21904)=first;
 output[1]=input[1];
 output[2]=input[2];
 output[3]=input[3];
 u32 finalValue=input[4];
 D_0034aa40=1;
 output[4]=finalValue;
}
