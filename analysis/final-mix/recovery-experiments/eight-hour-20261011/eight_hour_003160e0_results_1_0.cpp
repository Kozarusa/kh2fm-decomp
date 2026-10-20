#include "../common/types.h"
u32 func_003160e0(s32* first,s32* second,u32 payload,u32* output)
{
 register s32 a asm("$14")=first[1];
 register s32 b asm("$15")=second[1];
 asm("" : "+r"(a),"+r"(b));
 if(a==b){
 output[0]=payload;
 output[1]=6;
 output[3]=8;
 return 1;
 }
 return 0;
}
