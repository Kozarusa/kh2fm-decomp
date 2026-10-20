#include "../common/types.h"
u32 func_003160e0(s32* first,s32* second,u32 payload,u32* output)
{
 register s32 a asm("$14")=first[1];
 register s32 b asm("$15")=second[1];
 asm("" : "+r"(a),"+r"(b));
 if(a==b){
 register u32 six asm("$15")=6;
 asm("" : "+r"(six));
 output[0]=payload;
 register u32 eight asm("$14")=8;
 asm("" : "+r"(eight));
 output[1]=six;
 output[3]=eight;
 return 1;
 }
 return 0;
}
