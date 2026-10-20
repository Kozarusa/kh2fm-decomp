#include "../common/types.h"
u32 func_003160e0(s32* first,s32* second,u32 payload,u32* output)
{
 if(first[1]==second[1]){
 register u32 six asm("$15")=6;
 asm("" : "+r"(six));
 output[0]=payload;
 register u32 eight asm("$14")=8;
 asm("" : "+r"(eight));
 output[1]=six;
 output[3]=eight;
 asm("" : "+r"(six),"+r"(eight));
 return 1;
 }
 return 0;
}
